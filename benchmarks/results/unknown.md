#### [unknown](https://github.com/BobTheBuidler/faster-async-lru/blob/renovate/compile-async-lru-2.x/unknown) - [view benchmarks](https://github.com/BobTheBuidler/faster-async-lru/blob/renovate/compile-async-lru-2.x/unknown)

| Function | Reference Mean | Faster Mean | % Change | Speedup (%) | x Faster | Faster |
|----------|---------------|-------------|----------|-------------|----------|--------|
| `cache_clear_benchmark[bounded]` | 5.607515186047194e-07 | 3.989908572855978e-07 | 28.85% | 40.54% | 1.41x | ✅ |
| `cache_clear_benchmark[meth-bounded]` | 6.171222981481871e-07 | 4.233627037608656e-07 | 31.40% | 45.77% | 1.46x | ✅ |
| `cache_clear_benchmark[meth-unbounded]` | 6.150517312920129e-07 | 4.155925183177125e-07 | 32.43% | 47.99% | 1.48x | ✅ |
| `cache_clear_benchmark[unbounded]` | 5.59710175749561e-07 | 3.9834025910537576e-07 | 28.83% | 40.51% | 1.41x | ✅ |
| `cache_fill_eviction_benchmark` | 0.0898998432727299 | 0.08474976099999883 | 5.73% | 6.08% | 1.06x | ✅ |
| `cache_hit_benchmark[bounded]` | 0.0010460213944843437 | 0.0005383161262000037 | 48.54% | 94.31% | 1.94x | ✅ |
| `cache_hit_benchmark[meth-bounded]` | 0.0015540113317681656 | 0.0017640090558556293 | -13.51% | -11.90% | 0.88x | ❌ |
| `cache_hit_benchmark[meth-unbounded]` | 0.0015775762671878634 | 0.0017538906042402216 | -11.18% | -10.05% | 0.90x | ❌ |
| `cache_hit_benchmark[unbounded]` | 0.0010512226741453414 | 0.0005476997050082024 | 47.90% | 91.93% | 1.92x | ✅ |
| `cache_info_benchmark[bounded]` | 0.00047980968842412314 | 0.00037538244207677135 | 21.76% | 27.82% | 1.28x | ✅ |
| `cache_info_benchmark[meth-bounded]` | 0.0005354770100651654 | 0.00038072555930227626 | 28.90% | 40.65% | 1.41x | ✅ |
| `cache_info_benchmark[meth-unbounded]` | 0.0005369426503234465 | 0.0003811020607224302 | 29.02% | 40.89% | 1.41x | ✅ |
| `cache_info_benchmark[unbounded]` | 0.0004896749796019285 | 0.000379113101823813 | 22.58% | 29.16% | 1.29x | ✅ |
| `cache_invalidate_benchmark[bounded]` | 7.521305243093439e-05 | 2.7273279953003912e-05 | 63.74% | 175.78% | 2.76x | ✅ |
| `cache_invalidate_benchmark[meth-bounded]` | 0.0001513301719698087 | 0.00019939611842111066 | -31.76% | -24.11% | 0.76x | ❌ |
| `cache_invalidate_benchmark[meth-unbounded]` | 0.00015065508499160552 | 0.00020077957719991338 | -33.27% | -24.96% | 0.75x | ❌ |
| `cache_invalidate_benchmark[unbounded]` | 7.437684721201365e-05 | 2.7181807287850442e-05 | 63.45% | 173.63% | 2.74x | ✅ |
| `cache_miss_benchmark[bounded]` | 0.00015175560913719742 | 0.00017775648677237853 | -17.13% | -14.63% | 0.85x | ❌ |
| `cache_miss_benchmark[meth-bounded]` | 0.00021129894910993426 | 0.00023784277088994735 | -12.56% | -11.16% | 0.89x | ❌ |
| `cache_miss_benchmark[meth-unbounded]` | 0.00021365223076926646 | 0.0002426118844083925 | -13.55% | -11.94% | 0.88x | ❌ |
| `cache_miss_benchmark[unbounded]` | 0.00015090880769234578 | 0.0001815685220776317 | -20.32% | -16.89% | 0.83x | ❌ |
| `cache_ttl_expiry_benchmark[bounded]` | 1.1801266829240646e-05 | 1.1085401365351173e-05 | 6.07% | 6.46% | 1.06x | ✅ |
| `cache_ttl_expiry_benchmark[meth-bounded]` | 1.2565330386309157e-05 | 1.3335186820426539e-05 | -6.13% | -5.77% | 0.94x | ❌ |
| `cache_ttl_expiry_benchmark[meth-unbounded]` | 1.2511234384075282e-05 | 1.3294666854330648e-05 | -6.26% | -5.89% | 0.94x | ❌ |
| `cache_ttl_expiry_benchmark[unbounded]` | 1.1723669127603792e-05 | 1.109505379740429e-05 | 5.36% | 5.67% | 1.06x | ✅ |
| `concurrent_cache_hit_benchmark[bounded]` | 0.00048222795451655694 | 0.00042736091083455513 | 11.38% | 12.84% | 1.13x | ✅ |
| `concurrent_cache_hit_benchmark[meth-bounded]` | 0.0005456481873280661 | 0.0005703556740330734 | -4.53% | -4.33% | 0.96x | ❌ |
| `concurrent_cache_hit_benchmark[meth-unbounded]` | 0.0005534851457488234 | 0.0005717990976833471 | -3.31% | -3.20% | 0.97x | ❌ |
| `concurrent_cache_hit_benchmark[unbounded]` | 0.00048013015713541427 | 0.0004290939674908187 | 10.63% | 11.89% | 1.12x | ✅ |
| `internal_cache_hit_microbenchmark[bounded]` | 2.533729505671405e-05 | 9.86088175912094e-06 | 61.08% | 156.95% | 2.57x | ✅ |
| `internal_cache_hit_microbenchmark[unbounded]` | 2.5426270194473888e-05 | 9.752720777670797e-06 | 61.64% | 160.71% | 2.61x | ✅ |
| `internal_cache_miss_microbenchmark[bounded]` | 1.4159894945903319e-05 | 3.3925910296347765e-06 | 76.04% | 317.38% | 4.17x | ✅ |
| `internal_cache_miss_microbenchmark[unbounded]` | 1.4149728584253978e-05 | 3.3718590536587653e-06 | 76.17% | 319.64% | 4.20x | ✅ |
| `internal_task_done_callback_microbenchmark[cancelled-bounded]` | 0.0001456436325116613 | 0.00011002388097646424 | 24.46% | 32.37% | 1.32x | ✅ |
| `internal_task_done_callback_microbenchmark[cancelled-unbounded]` | 0.00014718278008863314 | 0.00010946918153545945 | 25.62% | 34.45% | 1.34x | ✅ |
| `internal_task_done_callback_microbenchmark[exception-bounded]` | 0.00017826221420868854 | 0.00013526196588599482 | 24.12% | 31.79% | 1.32x | ✅ |
| `internal_task_done_callback_microbenchmark[exception-unbounded]` | 0.0001779788904847975 | 0.00013576261183856947 | 23.72% | 31.10% | 1.31x | ✅ |
| `internal_task_done_callback_microbenchmark[finished-bounded]` | 0.00021138796765505016 | 0.00012400202722992346 | 41.34% | 70.47% | 1.70x | ✅ |
| `internal_task_done_callback_microbenchmark[finished-unbounded]` | 0.00021601482754962791 | 0.00012592038291781916 | 41.71% | 71.55% | 1.72x | ✅ |
