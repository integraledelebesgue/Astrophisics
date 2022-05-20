module MyQuadtree

using DataStructures: Stack
using Unitful
using Unitful: m, kg


export Point, Body, Quad, divide

struct Point
    x::Number
    y::Number
    Point(X::Number, Y::Number; units=false) = units ? new(X, Y) : new(X * m, Y * m)
end

struct Body
    mass::Number
    position::Point
    Body(state::Union{Array{Float64}, Array{Unitful.Quantity{Float64}}}; units=false) = units ? 
        new(abs(state[1]), Point(state[2], state[3]; units=true)) : new(abs(state[1]) * kg, Point(state[2], state[2]))
end

mutable struct Quad
    topLeft::Point
    botRight::Point

    bodies::Vector{Body}

    masscenter::Body

    NW::Union{Nothing, Quad}
    NE::Union{Nothing, Quad}
    SW::Union{Nothing, Quad}
    SE::Union{Nothing, Quad}

    Quad(topL::Point, botR::Point, bodyList::Vector{Body}, NWLink, NELink, SWLink, SELink) = new(topL, botR, bodyList, getMassCenter(bodyList), NWLink, NELink, SWLink, SELink)
end


function traverse(root::Quad)
    st = Stack{Quad}()
    push!(st, root)

    i = 1

    while(!isempty(st))
        curr = pop!(st)
        println(i, ". ", curr.bodies)
        i += 1

        if curr.NW ≢ nothing
            push!(st, curr.NW)
        end

        if curr.NE ≢ nothing
            push!(st, curr.NE)
        end

        if curr.SW ≢ nothing
            push!(st, curr.SW)
        end

        if curr.SE ≢ nothing
            push!(st, curr.SE)
        end
    end
    println()
end


function Base.:isless(p1::Body, p2::Body)::Bool
    return mod(p1.position) <= mod(p2.position)
end


function mod(p::Point)::Number
    return sqrt(p.x^2 + p.y^2)
end


function radius(bodies::Vector{Body})::Number
    return maximum([mod(body.position) for body ∈ bodies])
end


function divide(bodies)::Quad
    R = 1.1*radius(bodies)
    root = Quad(Point(-R, R; units=true), Point(R, -R; units=true), bodies, nothing, nothing, nothing, nothing)

    stack = Stack{Quad}()
    curr = root

    push!(stack, root)

    while !isempty(stack)
        curr = pop!(stack)

        qualify!(curr)

        if curr.NW !== nothing && length(curr.NW.bodies) > 1
            push!(stack, curr.NW)
            #println("!")
        end

        if curr.NE !== nothing && length(curr.NE.bodies) > 1
            push!(stack, curr.NE)
            #println("!!")
        end

        if curr.SW !== nothing && length(curr.SW.bodies) > 1
            push!(stack, curr.SW)
            #println("!!!")
        end

        if curr.SE !== nothing && length(curr.SE.bodies) > 1
            push!(stack, curr.SE)
            #println("!!!!")
        end
    end

    return root
end


function constructDivision(chunk::Quad)::Tuple{Quad, Quad, Quad, Quad}
    center = Point((chunk.topLeft.x + chunk.botRight.x)/2, (chunk.topLeft.y + chunk.botRight.y)/2; units=true)

    #println(center)

    NW = Quad(chunk.topLeft, center, Vector{Body}(), nothing, nothing, nothing, nothing)
    NE = Quad(Point(center.x, chunk.topLeft.y; units=true), Point(chunk.botRight.x, center.y; units=true), Vector{Body}(), nothing, nothing, nothing, nothing)
    SW = Quad(Point(chunk.topLeft.x, center.y; units=true), Point(center.x, chunk.botRight.y; units=true), Vector{Body}(), nothing, nothing, nothing, nothing)
    SE = Quad(center, chunk.botRight, Vector{Body}(), nothing, nothing, nothing, nothing)

    return NW, NE, SW, SE
end


function isElement(p::Body, topl::Point, botr::Point)::Bool
    return topl.x <= p.position.x && p.position.x <= botr.x && botr.y <= p.position.y && p.position.y <= topl.y
end


function qualify!(chunk::Quad)
    NW, NE, SW, SE = constructDivision(chunk)

    #println(NW, NE, SW, SE)

    for point ∈ chunk.bodies
        #println(".")
        if isElement(point, NW.topLeft, NW.botRight)
            #println("a")
            push!(NW.bodies, point)
        elseif isElement(point, NE.topLeft, NE.botRight)
            #println("b")
            push!(NE.bodies, point)
        elseif isElement(point, SW.topLeft, SW.botRight)
            #println("c")
            push!(SW.bodies, point)
        elseif isElement(point, SE.topLeft, SE.botRight)
            #println("d")
            push!(SE.bodies, point)
        end
    end

    if length(NW.bodies) > 0
        #println("   !")
        chunk.NW = NW
    end

    if length(NE.bodies) > 0
        #println("   !!")
        chunk.NE = NE
    end

    if length(SW.bodies) > 0
        #println("   !!!")
        chunk.SW = SW
    end

    if length(SE.bodies) > 0
        #println(   "!!!!")
        chunk.SE = SE
    end
end


function getMassCenter(bodies::Vector{Body})::Body
    center = [0.0*kg, 0.0*kg*m, 0.0*kg*m]

    for body in bodies
        center[1] += body.mass
        center[2] += body.mass * body.position.x
        center[3] += body.mass * body.position.y
    end

    center[2] /= center[1]
    center[3] /= center[1]

    return Body(center; units=true)
end

end