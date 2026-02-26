#### [unknown](https://github.com/BobTheBuidler/faster-async-lru/blob/renovate/compile-major-github-artifact-actions/unknown) - [view benchmarks](https://github.com/BobTheBuidler/faster-async-lru/blob/renovate/compile-major-github-artifact-actions/unknown)

| Function | Reference Mean | Faster Mean | % Change | Speedup (%) | x Faster | Faster |
|----------|---------------|-------------|----------|-------------|----------|--------|
| `cache_clear_benchmark[bounded]` | 5.700360427751505e-07 | 4.150180446817383e-07 | 27.19% | 37.35% | 1.37x | ✅ |
| `cache_clear_benchmark[meth-bounded]` | 6.135468433362235e-07 | 4.015239174482275e-07 | 34.56% | 52.80% | 1.53x | ✅ |
| `cache_clear_benchmark[meth-unbounded]` | 6.11888188431765e-07 | 4.0415578593184085e-07 | 33.95% | 51.40% | 1.51x | ✅ |
| `cache_clear_benchmark[unbounded]` | 5.766511408993907e-07 | 4.0160182932512196e-07 | 30.36% | 43.59% | 1.44x | ✅ |
| `cache_fill_eviction_benchmark` | 0.08925707874999489 | 0.08292457361538325 | 7.09% | 7.64% | 1.08x | ✅ |
| `cache_hit_benchmark[bounded]` | 0.0010278036028614716 | 0.0005360944190144924 | 47.84% | 91.72% | 1.92x | ✅ |
| `cache_hit_benchmark[meth-bounded]` | 0.001551365880503674 | 0.001776538245079245 | -14.51% | -12.67% | 0.87x | ❌ |
| `cache_hit_benchmark[meth-unbounded]` | 0.001532791681676434 | 0.0017796830333921348 | -16.11% | -13.87% | 0.86x | ❌ |
| `cache_hit_benchmark[unbounded]` | 0.001051087150367962 | 0.0005357192781268821 | 49.03% | 96.20% | 1.96x | ✅ |
| `cache_info_benchmark[bounded]` | 0.0004933800297846704 | 0.00039681564001575596 | 19.57% | 24.33% | 1.24x | ✅ |
| `cache_info_benchmark[meth-bounded]` | 0.0005336595789761775 | 0.00039732419251006676 | 25.55% | 34.31% | 1.34x | ✅ |
| `cache_info_benchmark[meth-unbounded]` | 0.0005349904275026848 | 0.0003884016290716231 | 27.40% | 37.74% | 1.38x | ✅ |
| `cache_info_benchmark[unbounded]` | 0.0005156393255073194 | 0.00038988316633114254 | 24.39% | 32.25% | 1.32x | ✅ |
| `cache_invalidate_benchmark[bounded]` | 7.442003427802302e-05 | 2.9724073924814894e-05 | 60.06% | 150.37% | 2.50x | ✅ |
| `cache_invalidate_benchmark[meth-bounded]` | 0.0001555336504759445 | 0.0001964783726274694 | -26.33% | -20.84% | 0.79x | ❌ |
| `cache_invalidate_benchmark[meth-unbounded]` | 0.00015600063422017938 | 0.00019646441008358383 | -25.94% | -20.60% | 0.79x | ❌ |
| `cache_invalidate_benchmark[unbounded]` | 7.567094566888936e-05 | 2.909181828754904e-05 | 61.55% | 160.11% | 2.60x | ✅ |
| `cache_miss_benchmark[bounded]` | 0.0001503757320079801 | 0.00018105406532849792 | -20.40% | -16.94% | 0.83x | ❌ |
| `cache_miss_benchmark[meth-bounded]` | 0.0002168572151581952 | 0.00024328344050566475 | -12.19% | -10.86% | 0.89x | ❌ |
| `cache_miss_benchmark[meth-unbounded]` | 0.00021347140837719273 | 0.00023932987862807892 | -12.11% | -10.80% | 0.89x | ❌ |
| `cache_miss_benchmark[unbounded]` | 0.000152037372640627 | 0.00018031684261653799 | -18.60% | -15.68% | 0.84x | ❌ |
| `cache_ttl_expiry_benchmark[bounded]` | 1.1602691349220809e-05 | 1.078330570873207e-05 | 7.06% | 7.60% | 1.08x | ✅ |
| `cache_ttl_expiry_benchmark[meth-bounded]` | 1.2571616206303562e-05 | 1.2768163902925251e-05 | -1.56% | -1.54% | 0.98x | ❌ |
| `cache_ttl_expiry_benchmark[meth-unbounded]` | 1.227681803993045e-05 | 1.282239219975196e-05 | -4.44% | -4.25% | 0.96x | ❌ |
| `cache_ttl_expiry_benchmark[unbounded]` | 1.1653737327794928e-05 | 1.0950856658873575e-05 | 6.03% | 6.42% | 1.06x | ✅ |
| `concurrent_cache_hit_benchmark[bounded]` | 0.000474930532474402 | 0.00042876266735861267 | 9.72% | 10.77% | 1.11x | ✅ |
| `concurrent_cache_hit_benchmark[meth-bounded]` | 0.0005298712271155637 | 0.0005598928810333495 | -5.67% | -5.36% | 0.95x | ❌ |
| `concurrent_cache_hit_benchmark[meth-unbounded]` | 0.0005319873573169128 | 0.0005592459409124472 | -5.12% | -4.87% | 0.95x | ❌ |
| `concurrent_cache_hit_benchmark[unbounded]` | 0.00047406339528672874 | 0.0004265210967109909 | 10.03% | 11.15% | 1.11x | ✅ |
| `internal_cache_hit_microbenchmark[bounded]` | 2.5791571272719177e-05 | 9.710021051584726e-06 | 62.35% | 165.62% | 2.66x | ✅ |
| `internal_cache_hit_microbenchmark[unbounded]` | 2.6007146354142513e-05 | 9.715699862508027e-06 | 62.64% | 167.68% | 2.68x | ✅ |
| `internal_cache_miss_microbenchmark[bounded]` | 1.41576173259297e-05 | 3.7445154458573052e-06 | 73.55% | 278.09% | 3.78x | ✅ |
| `internal_cache_miss_microbenchmark[unbounded]` | 1.4287391288473145e-05 | 3.873439211042749e-06 | 72.89% | 268.86% | 3.69x | ✅ |
| `internal_task_done_callback_microbenchmark[cancelled-bounded]` | 0.00014827678554038282 | 0.00010859349473043595 | 26.76% | 36.54% | 1.37x | ✅ |
| `internal_task_done_callback_microbenchmark[cancelled-unbounded]` | 0.00014596657072842557 | 0.00010944494868649415 | 25.02% | 33.37% | 1.33x | ✅ |
| `internal_task_done_callback_microbenchmark[exception-bounded]` | 0.00017977120601650926 | 0.00013155537978158148 | 26.82% | 36.65% | 1.37x | ✅ |
| `internal_task_done_callback_microbenchmark[exception-unbounded]` | 0.00017941756076934567 | 0.00013106124386036603 | 26.95% | 36.90% | 1.37x | ✅ |
| `internal_task_done_callback_microbenchmark[finished-bounded]` | 0.00021014189399190398 | 0.00012908297656929668 | 38.57% | 62.80% | 1.63x | ✅ |
| `internal_task_done_callback_microbenchmark[finished-unbounded]` | 0.00020865992507692214 | 0.00013030081215232867 | 37.55% | 60.14% | 1.60x | ✅ |
