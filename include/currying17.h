#pragma once

template<typename... Ts>
auto partial_add3(Ts... xs)
{
    static_assert(sizeof...(xs) <= 3);

    if constexpr (sizeof...(xs) == 3) {
        return (0 + ... + xs);
    } else {
        return [xs...](auto... ys) {
            return partial_add3(xs..., ys...);
        };
    }
}
