#### [unknown](https://github.com/BobTheBuidler/faster-async-lru/blob/renovate/compile-async-lru-2.x/unknown) - [view benchmarks](https://github.com/BobTheBuidler/faster-async-lru/blob/renovate/compile-async-lru-2.x/unknown)

| Function | Reference Mean | Faster Mean | % Change | Speedup (%) | x Faster | Faster |
|----------|---------------|-------------|----------|-------------|----------|--------|
| `cache_clear_benchmark[bounded]` | 5.027500086371454e-07 | 3.597397712033851e-07 | 28.45% | 39.75% | 1.40x | ✅ |
| `cache_clear_benchmark[meth-bounded]` | 5.591866150251177e-07 | 3.636393087318178e-07 | 34.97% | 53.78% | 1.54x | ✅ |
| `cache_clear_benchmark[meth-unbounded]` | 5.575508931486454e-07 | 3.632244708877239e-07 | 34.85% | 53.50% | 1.54x | ✅ |
| `cache_clear_benchmark[unbounded]` | 5.008231440433612e-07 | 3.6361174123603137e-07 | 27.40% | 37.74% | 1.38x | ✅ |
| `cache_fill_eviction_benchmark` | 0.07034527019999832 | 0.06636627431250108 | 5.66% | 6.00% | 1.06x | ✅ |
| `cache_hit_benchmark[bounded]` | 0.0009128761947420828 | 0.000469633241531889 | 48.55% | 94.38% | 1.94x | ✅ |
| `cache_hit_benchmark[meth-bounded]` | 0.0013900948616262614 | 0.0016333003990061277 | -17.50% | -14.89% | 0.85x | ❌ |
| `cache_hit_benchmark[meth-unbounded]` | 0.0013937972301136298 | 0.0016302606239601552 | -16.97% | -14.50% | 0.85x | ❌ |
| `cache_hit_benchmark[unbounded]` | 0.0008947275391539441 | 0.00046756069742063627 | 47.74% | 91.36% | 1.91x | ✅ |
| `cache_info_benchmark[bounded]` | 0.0004440116254087692 | 0.00035887001728018635 | 19.18% | 23.72% | 1.24x | ✅ |
| `cache_info_benchmark[meth-bounded]` | 0.0004939254482758163 | 0.000363474131159305 | 26.41% | 35.89% | 1.36x | ✅ |
| `cache_info_benchmark[meth-unbounded]` | 0.0004923934517241407 | 0.0003585797126520529 | 27.18% | 37.32% | 1.37x | ✅ |
| `cache_info_benchmark[unbounded]` | 0.00044442743633881947 | 0.00036016620548456305 | 18.96% | 23.40% | 1.23x | ✅ |
| `cache_invalidate_benchmark[bounded]` | 7.159200422313821e-05 | 2.6436394417695806e-05 | 63.07% | 170.81% | 2.71x | ✅ |
| `cache_invalidate_benchmark[meth-bounded]` | 0.000137685150069531 | 0.00017828818642024382 | -29.49% | -22.77% | 0.77x | ❌ |
| `cache_invalidate_benchmark[meth-unbounded]` | 0.0001375918190458057 | 0.00017480436372022806 | -27.05% | -21.29% | 0.79x | ❌ |
| `cache_invalidate_benchmark[unbounded]` | 7.162577094324297e-05 | 2.6020833126030768e-05 | 63.67% | 175.26% | 2.75x | ✅ |
| `cache_miss_benchmark[bounded]` | 0.0001296850344827439 | 0.00016117384848527507 | -24.28% | -19.54% | 0.80x | ❌ |
| `cache_miss_benchmark[meth-bounded]` | 0.00018422898428325837 | 0.00021923688912105075 | -19.00% | -15.97% | 0.84x | ❌ |
| `cache_miss_benchmark[meth-unbounded]` | 0.00018427407128751726 | 0.00022226025571682112 | -20.61% | -17.09% | 0.83x | ❌ |
| `cache_miss_benchmark[unbounded]` | 0.00012817448387107908 | 0.00016063055511002214 | -25.32% | -20.21% | 0.80x | ❌ |
| `cache_ttl_expiry_benchmark[bounded]` | 8.860860456791017e-06 | 8.186834829885156e-06 | 7.61% | 8.23% | 1.08x | ✅ |
| `cache_ttl_expiry_benchmark[meth-bounded]` | 9.315753507529467e-06 | 1.0004767661055292e-05 | -7.40% | -6.89% | 0.93x | ❌ |
| `cache_ttl_expiry_benchmark[meth-unbounded]` | 9.352921831391024e-06 | 1.0005575261848138e-05 | -6.98% | -6.52% | 0.93x | ❌ |
| `cache_ttl_expiry_benchmark[unbounded]` | 8.860043142762263e-06 | 8.205341129106205e-06 | 7.39% | 7.98% | 1.08x | ✅ |
| `concurrent_cache_hit_benchmark[bounded]` | 0.00040555340136412733 | 0.00036087048773496397 | 11.02% | 12.38% | 1.12x | ✅ |
| `concurrent_cache_hit_benchmark[meth-bounded]` | 0.0004529466686189395 | 0.0004900555410683178 | -8.19% | -7.57% | 0.92x | ❌ |
| `concurrent_cache_hit_benchmark[meth-unbounded]` | 0.0004601674374696458 | 0.000488293098575962 | -6.11% | -5.76% | 0.94x | ❌ |
| `concurrent_cache_hit_benchmark[unbounded]` | 0.0004048909973510758 | 0.00037267687270501276 | 7.96% | 8.64% | 1.09x | ✅ |
| `internal_cache_hit_microbenchmark[bounded]` | 2.4270687495975937e-05 | 8.236759085280742e-06 | 66.06% | 194.66% | 2.95x | ✅ |
| `internal_cache_hit_microbenchmark[unbounded]` | 2.4356099831102896e-05 | 8.27815244461215e-06 | 66.01% | 194.22% | 2.94x | ✅ |
| `internal_cache_miss_microbenchmark[bounded]` | 1.3492674049754577e-05 | 3.3894101855831e-06 | 74.88% | 298.08% | 3.98x | ✅ |
| `internal_cache_miss_microbenchmark[unbounded]` | 1.3487511371733657e-05 | 3.3446922518328247e-06 | 75.20% | 303.25% | 4.03x | ✅ |
| `internal_task_done_callback_microbenchmark[cancelled-bounded]` | 0.00012814235949225815 | 0.00010031557891604869 | 21.72% | 27.74% | 1.28x | ✅ |
| `internal_task_done_callback_microbenchmark[cancelled-unbounded]` | 0.000129143115251026 | 0.00010038360585013368 | 22.27% | 28.65% | 1.29x | ✅ |
| `internal_task_done_callback_microbenchmark[exception-bounded]` | 0.00016644992152800337 | 0.00012837297939926183 | 22.88% | 29.66% | 1.30x | ✅ |
| `internal_task_done_callback_microbenchmark[exception-unbounded]` | 0.00016615914750136437 | 0.00012719323162191465 | 23.45% | 30.64% | 1.31x | ✅ |
| `internal_task_done_callback_microbenchmark[finished-bounded]` | 0.00020652371390145053 | 0.00010923094103885441 | 47.11% | 89.07% | 1.89x | ✅ |
| `internal_task_done_callback_microbenchmark[finished-unbounded]` | 0.0002107600042007185 | 0.00010983252235008682 | 47.89% | 91.89% | 1.92x | ✅ |
