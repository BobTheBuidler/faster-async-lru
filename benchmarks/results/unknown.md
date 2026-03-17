#### [unknown](https://github.com/BobTheBuidler/faster-async-lru/blob/renovate/compile-coverage-7.x/unknown) - [view benchmarks](https://github.com/BobTheBuidler/faster-async-lru/blob/renovate/compile-coverage-7.x/unknown)

| Function | Reference Mean | Faster Mean | % Change | Speedup (%) | x Faster | Faster |
|----------|---------------|-------------|----------|-------------|----------|--------|
| `cache_clear_benchmark[bounded]` | 5.631379889738713e-07 | 3.9637517075421043e-07 | 29.61% | 42.07% | 1.42x | ✅ |
| `cache_clear_benchmark[meth-bounded]` | 6.018307598540932e-07 | 3.9779981719490376e-07 | 33.90% | 51.29% | 1.51x | ✅ |
| `cache_clear_benchmark[meth-unbounded]` | 6.028287951417167e-07 | 4.0135552973653863e-07 | 33.42% | 50.20% | 1.50x | ✅ |
| `cache_clear_benchmark[unbounded]` | 5.584772494974038e-07 | 3.934194746535978e-07 | 29.55% | 41.95% | 1.42x | ✅ |
| `cache_fill_eviction_benchmark` | 0.08944092783333464 | 0.08296960553846261 | 7.24% | 7.80% | 1.08x | ✅ |
| `cache_hit_benchmark[bounded]` | 0.001039656565264287 | 0.0005609350982759258 | 46.05% | 85.34% | 1.85x | ✅ |
| `cache_hit_benchmark[meth-bounded]` | 0.0015599419937207793 | 0.0018434847257769056 | -18.18% | -15.38% | 0.85x | ❌ |
| `cache_hit_benchmark[meth-unbounded]` | 0.0015597099938363219 | 0.0018661457981819364 | -19.65% | -16.42% | 0.84x | ❌ |
| `cache_hit_benchmark[unbounded]` | 0.001043831937763802 | 0.0005589276793200915 | 46.45% | 86.76% | 1.87x | ✅ |
| `cache_info_benchmark[bounded]` | 0.0005207057825125503 | 0.0004046307489270834 | 22.29% | 28.69% | 1.29x | ✅ |
| `cache_info_benchmark[meth-bounded]` | 0.0005745557050359084 | 0.00038566006800321706 | 32.88% | 48.98% | 1.49x | ✅ |
| `cache_info_benchmark[meth-unbounded]` | 0.0005600683226359862 | 0.00037699092576269416 | 32.69% | 48.56% | 1.49x | ✅ |
| `cache_info_benchmark[unbounded]` | 0.0005195341590309024 | 0.0003807636946017813 | 26.71% | 36.45% | 1.36x | ✅ |
| `cache_invalidate_benchmark[bounded]` | 7.508554471845249e-05 | 3.0182913892615714e-05 | 59.80% | 148.77% | 2.49x | ✅ |
| `cache_invalidate_benchmark[meth-bounded]` | 0.000154574279746247 | 0.00019848778681496416 | -28.41% | -22.12% | 0.78x | ❌ |
| `cache_invalidate_benchmark[meth-unbounded]` | 0.0001572840299451338 | 0.00019900178010049877 | -26.52% | -20.96% | 0.79x | ❌ |
| `cache_invalidate_benchmark[unbounded]` | 7.591077584812684e-05 | 2.956281267933153e-05 | 61.06% | 156.78% | 2.57x | ✅ |
| `cache_miss_benchmark[bounded]` | 0.00014864825490153847 | 0.00017987147407417845 | -21.00% | -17.36% | 0.83x | ❌ |
| `cache_miss_benchmark[meth-bounded]` | 0.00021073983698288143 | 0.00024147949875324607 | -14.59% | -12.73% | 0.87x | ❌ |
| `cache_miss_benchmark[meth-unbounded]` | 0.00021127169326698385 | 0.00024229608311705827 | -14.68% | -12.80% | 0.87x | ❌ |
| `cache_miss_benchmark[unbounded]` | 0.00015169123349004378 | 0.00017902989311204207 | -18.02% | -15.27% | 0.85x | ❌ |
| `cache_ttl_expiry_benchmark[bounded]` | 1.1914987321812077e-05 | 1.12772068941868e-05 | 5.35% | 5.66% | 1.06x | ✅ |
| `cache_ttl_expiry_benchmark[meth-bounded]` | 1.2556528601411937e-05 | 1.3249538332880761e-05 | -5.52% | -5.23% | 0.95x | ❌ |
| `cache_ttl_expiry_benchmark[meth-unbounded]` | 1.2543249114926112e-05 | 1.3109367898236402e-05 | -4.51% | -4.32% | 0.96x | ❌ |
| `cache_ttl_expiry_benchmark[unbounded]` | 1.1618880754429895e-05 | 1.1198585133531299e-05 | 3.62% | 3.75% | 1.04x | ✅ |
| `concurrent_cache_hit_benchmark[bounded]` | 0.0004810490350240131 | 0.0004304759516883474 | 10.51% | 11.75% | 1.12x | ✅ |
| `concurrent_cache_hit_benchmark[meth-bounded]` | 0.0005363431458709227 | 0.0005683909638553966 | -5.98% | -5.64% | 0.94x | ❌ |
| `concurrent_cache_hit_benchmark[meth-unbounded]` | 0.0005376989253462313 | 0.0005699697450499575 | -6.00% | -5.66% | 0.94x | ❌ |
| `concurrent_cache_hit_benchmark[unbounded]` | 0.00048030273447729886 | 0.00043243992946624373 | 9.97% | 11.07% | 1.11x | ✅ |
| `internal_cache_hit_microbenchmark[bounded]` | 2.5650946605997143e-05 | 9.670721383694102e-06 | 62.30% | 165.24% | 2.65x | ✅ |
| `internal_cache_hit_microbenchmark[unbounded]` | 2.6066941210295392e-05 | 9.71643507387744e-06 | 62.73% | 168.28% | 2.68x | ✅ |
| `internal_cache_miss_microbenchmark[bounded]` | 1.4810537125277672e-05 | 3.4457501799286813e-06 | 76.73% | 329.82% | 4.30x | ✅ |
| `internal_cache_miss_microbenchmark[unbounded]` | 1.4829624724003463e-05 | 3.52030030640001e-06 | 76.26% | 321.26% | 4.21x | ✅ |
| `internal_task_done_callback_microbenchmark[cancelled-bounded]` | 0.00014578943615587025 | 0.00010727267202362441 | 26.42% | 35.91% | 1.36x | ✅ |
| `internal_task_done_callback_microbenchmark[cancelled-unbounded]` | 0.00014934622204241862 | 0.00010846060565393293 | 27.38% | 37.70% | 1.38x | ✅ |
| `internal_task_done_callback_microbenchmark[exception-bounded]` | 0.00017982253500195281 | 0.0001312982088235549 | 26.98% | 36.96% | 1.37x | ✅ |
| `internal_task_done_callback_microbenchmark[exception-unbounded]` | 0.0001808958958483703 | 0.00013217671815245847 | 26.93% | 36.86% | 1.37x | ✅ |
| `internal_task_done_callback_microbenchmark[finished-bounded]` | 0.00020759523816690854 | 0.00012833469608884381 | 38.18% | 61.76% | 1.62x | ✅ |
| `internal_task_done_callback_microbenchmark[finished-unbounded]` | 0.000209554909801382 | 0.00012896206423550105 | 38.46% | 62.49% | 1.62x | ✅ |
