#### [unknown](https://github.com/BobTheBuidler/faster-async-lru/blob/BobTheBuidler-patch-2/unknown) - [view benchmarks](https://github.com/BobTheBuidler/faster-async-lru/blob/BobTheBuidler-patch-2/unknown)

| Function | Reference Mean | Faster Mean | % Change | Speedup (%) | x Faster | Faster |
|----------|---------------|-------------|----------|-------------|----------|--------|
| `cache_clear_benchmark[bounded]` | 5.737417881313465e-07 | 4.0338523118926583e-07 | 29.69% | 42.23% | 1.42x | ✅ |
| `cache_clear_benchmark[meth-bounded]` | 6.223535570297544e-07 | 4.0998300142667024e-07 | 34.12% | 51.80% | 1.52x | ✅ |
| `cache_clear_benchmark[meth-unbounded]` | 6.712060123642454e-07 | 4.048718742496336e-07 | 39.68% | 65.78% | 1.66x | ✅ |
| `cache_clear_benchmark[unbounded]` | 5.758023473880685e-07 | 4.100024595282056e-07 | 28.79% | 40.44% | 1.40x | ✅ |
| `cache_fill_eviction_benchmark` | 0.09111752390908702 | 0.0833965260769105 | 8.47% | 9.26% | 1.09x | ✅ |
| `cache_hit_benchmark[bounded]` | 0.001056165424859431 | 0.0005915082531407012 | 43.99% | 78.55% | 1.79x | ✅ |
| `cache_hit_benchmark[meth-bounded]` | 0.0016104941250000095 | 0.0017836711511830749 | -10.75% | -9.71% | 0.90x | ❌ |
| `cache_hit_benchmark[meth-unbounded]` | 0.0016063411938606565 | 0.0017933390777582054 | -11.64% | -10.43% | 0.90x | ❌ |
| `cache_hit_benchmark[unbounded]` | 0.0010688630985016049 | 0.0005917287499997456 | 44.64% | 80.63% | 1.81x | ✅ |
| `cache_info_benchmark[bounded]` | 0.000491199767885522 | 0.0003704528416832972 | 24.58% | 32.59% | 1.33x | ✅ |
| `cache_info_benchmark[meth-bounded]` | 0.0005360256025788505 | 0.0004019490004035865 | 25.01% | 33.36% | 1.33x | ✅ |
| `cache_info_benchmark[meth-unbounded]` | 0.000536132203444864 | 0.0003956113044550136 | 26.21% | 35.52% | 1.36x | ✅ |
| `cache_info_benchmark[unbounded]` | 0.00048880570359164 | 0.00038797146925121924 | 20.63% | 25.99% | 1.26x | ✅ |
| `cache_invalidate_benchmark[bounded]` | 7.48748606948992e-05 | 2.6167994810476805e-05 | 65.05% | 186.13% | 2.86x | ✅ |
| `cache_invalidate_benchmark[meth-bounded]` | 0.00015257417597334505 | 0.00020117125719392207 | -31.85% | -24.16% | 0.76x | ❌ |
| `cache_invalidate_benchmark[meth-unbounded]` | 0.00015200635453536295 | 0.0002016467569525141 | -32.66% | -24.62% | 0.75x | ❌ |
| `cache_invalidate_benchmark[unbounded]` | 7.605235620192039e-05 | 2.625373782167551e-05 | 65.48% | 189.68% | 2.90x | ✅ |
| `cache_miss_benchmark[bounded]` | 0.00015461401478027425 | 0.00018226967341733246 | -17.89% | -15.17% | 0.85x | ❌ |
| `cache_miss_benchmark[meth-bounded]` | 0.00021909117232524902 | 0.00024114145093038806 | -10.06% | -9.14% | 0.91x | ❌ |
| `cache_miss_benchmark[meth-unbounded]` | 0.00021700585604170143 | 0.00024295843979231418 | -11.96% | -10.68% | 0.89x | ❌ |
| `cache_miss_benchmark[unbounded]` | 0.00015766821761591663 | 0.00018151055584345253 | -15.12% | -13.14% | 0.87x | ❌ |
| `cache_ttl_expiry_benchmark[bounded]` | 1.201348538299853e-05 | 1.1305471348786507e-05 | 5.89% | 6.26% | 1.06x | ✅ |
| `cache_ttl_expiry_benchmark[meth-bounded]` | 1.2930231287967966e-05 | 1.3121441174505763e-05 | -1.48% | -1.46% | 0.99x | ❌ |
| `cache_ttl_expiry_benchmark[meth-unbounded]` | 1.2862012915599284e-05 | 1.3177665381006423e-05 | -2.45% | -2.40% | 0.98x | ❌ |
| `cache_ttl_expiry_benchmark[unbounded]` | 1.1971870150458745e-05 | 1.1391081862598717e-05 | 4.85% | 5.10% | 1.05x | ✅ |
| `concurrent_cache_hit_benchmark[bounded]` | 0.0004773102730592851 | 0.00042540545244541556 | 10.87% | 12.20% | 1.12x | ✅ |
| `concurrent_cache_hit_benchmark[meth-bounded]` | 0.0005452265995488225 | 0.0005759155976730388 | -5.63% | -5.33% | 0.95x | ❌ |
| `concurrent_cache_hit_benchmark[meth-unbounded]` | 0.0005452876062117181 | 0.000564477740891253 | -3.52% | -3.40% | 0.97x | ❌ |
| `concurrent_cache_hit_benchmark[unbounded]` | 0.0004820803672260853 | 0.0004258775656797379 | 11.66% | 13.20% | 1.13x | ✅ |
| `internal_cache_hit_microbenchmark[bounded]` | 2.5677786256178927e-05 | 9.71642323414469e-06 | 62.16% | 164.27% | 2.64x | ✅ |
| `internal_cache_hit_microbenchmark[unbounded]` | 2.5698121080372074e-05 | 9.696339747336011e-06 | 62.27% | 165.03% | 2.65x | ✅ |
| `internal_cache_miss_microbenchmark[bounded]` | 1.4086460340620658e-05 | 3.5042109407962492e-06 | 75.12% | 301.99% | 4.02x | ✅ |
| `internal_cache_miss_microbenchmark[unbounded]` | 1.7826845778874137e-05 | 3.665385789089574e-06 | 79.44% | 386.36% | 4.86x | ✅ |
| `internal_task_done_callback_microbenchmark[cancelled-bounded]` | 0.0001500996529425278 | 0.00010829558200595518 | 27.85% | 38.60% | 1.39x | ✅ |
| `internal_task_done_callback_microbenchmark[cancelled-unbounded]` | 0.00014871506517423193 | 0.00010698897027053244 | 28.06% | 39.00% | 1.39x | ✅ |
| `internal_task_done_callback_microbenchmark[exception-bounded]` | 0.00017772329202545364 | 0.00013402879608342828 | 24.59% | 32.60% | 1.33x | ✅ |
| `internal_task_done_callback_microbenchmark[exception-unbounded]` | 0.00018123902158393912 | 0.00013430024296003866 | 25.90% | 34.95% | 1.35x | ✅ |
| `internal_task_done_callback_microbenchmark[finished-bounded]` | 0.00021620879622001883 | 0.0001307651496098048 | 39.52% | 65.34% | 1.65x | ✅ |
| `internal_task_done_callback_microbenchmark[finished-unbounded]` | 0.00021752068665304282 | 0.0001234308440657961 | 43.26% | 76.23% | 1.76x | ✅ |
