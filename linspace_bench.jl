using BenchmarkTools

function test_naive(a,b,n)
    ret = zeros(Int64(n))
    dx = (b-a)/n
    for i = 1:Int64(n)
        ret[i] = a+i*dx
    end
    return ret
end

function test_better(a,b,n)
    ret = Array{Float64,1}(undef, Int64(n))
    dx = (b-a)/n
    for i in eachindex(ret)
        ret[i] = a+i*dx
    end
    return ret
end



@btime test_better(0,1e5,1e5+1)
