push!(LOAD_PATH, @__DIR__)

using MyPhysics
using MyQuadtree
using Unitful: m, kg


function generateBodies(count::Number, explicite...; verbose=false, toFile=nothing)::Array{Body, 1}
    result::Array{Body, 1} = [[Body(ex) for ex ∈ explicite] ; collect(generate(count - length(explicite)))]

    if verbose
        display(result)
    end

    if toFile ≢ nothing
       # TODO: Write to file 
    end

    return result
end

B = generateBodies(10, [1.0, 2.0, 3.0], [0.0, 0.0, 0.0]; verbose = false)

getResultants(B, 0.3)
