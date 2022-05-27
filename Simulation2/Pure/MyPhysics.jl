module MyPhysics

using DataStructures
using MyQuadtree
using Unitful
using Unitful: m, kg

export getResultants, generate


function getForce(particle::Body, source::Body)::Array{Number, 1}
    return versor(particle.position, source.position) .* (particle.mass * source.mass)
end


function versor(p1::Point, p2::Point)::Array{Number, 1}
    return [p2.x - p1.x, p2.y - p1.y] ./ (distance(p1, p2)^3)
end


function distance(p1::Point, p2::Point)::Number
    return sqrt((p1.x - p2.x)^2 + (p1.y - p2.y)^2)
end


function getResultants(bodies::Vector{Body}, threshold::Float64)::Vector{Array{Number, 1}}
    root = divide(bodies)
    result = Vector{Array{Unitful.Quantity{Float64}}}()

    for body ∈ bodies
        push!(result, resultant(body, root, threshold))
    end

    return result
end


function resultant(body::Body, root::Quad, threshold::Float64)::Array{Number, 1}
    stack = Stack{Quad}()
    curr::Quad = root
    result = [0*kg^2/m^3, 0*kg^2/m^3]

    if root.NW !== nothing
        push!(stack, root.NW)
    end

    if root.NE !== nothing
        push!(stack, root.NE)
    end

    if root.SW !== nothing
        push!(stack, root.SW)
    end

    if root.SE !== nothing
        push!(stack, root.SE)
    end

    while !isempty(stack)
        curr = pop!(stack)
        dist = distance(body.position, curr.masscenter.position)
        diam = distance(curr.topLeft, curr.botRight)
        
        if dist == 0
            continue
        
        elseif diam/dist < threshold
            result += getForce(body, curr.masscenter)

        elseif curr.NW !== nothing && curr.NE !== nothing && curr.SW !== nothing && curr.SE !== nothing
            result += getForce(body, curr.bodies[1])

        else
            if curr.NW !== nothing
                push!(stack, curr.NW)
            end
        
            if curr.NE !== nothing
                push!(stack, curr.NE)
            end
        
            if curr.SW !== nothing
                push!(stack, curr.SW)
            end
        
            if curr.SE !== nothing
                push!(stack, curr.SE)
            end
        end
    end
end


function generate(count::Int)::Channel
    Channel() do channel
        for _ ∈ 1:count
            put!(channel, Body(randn(Float64, 3)))
        end
    end
end

end