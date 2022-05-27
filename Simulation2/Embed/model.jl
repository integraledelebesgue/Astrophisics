module model

export Body, Model

struct Body
    mass::Float64
    x::Float64
    y::Float64
    vx::Float64
    vy::Float64

    Body(state::Vector{Float64}) = new(abs(state[1]), state[2], state[3], state[4], state[5])
end

mutable struct Model
    bodies::Vector{Body}
    count::Int128
    time::Float64
    accuracy::Float64
    state::Array{Float64, 2}
    db::Union{String, Nothing}
    collisions_allowed::Bool

    Model(Bodies, Time, Accuracy, DataBase; database = false, collisions=false) = new(
        Bodies, 
        Time, 
        Accuracy, 
        makeState(Bodies), 
        database ? DataBase : nothing, 
        collisions
        )

end

function makeState(bodies::Vector{Body})::Array{Float64, 2}
    return [[body.x, body.y, body.vx, body.vy] for body ∈ bodies]
end