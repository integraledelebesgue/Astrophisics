module generation

using model: Body, Model

export generateBodies

# Maybe more fancy generation in the futute (readymade galaxies, etc.)

function generate(count::Int)::Channel
    Channel() do channel
        for _ ∈ 1:count
            put!(channel, Body(randn(Float64, 5)))
        end
    end
end

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

end