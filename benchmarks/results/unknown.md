#### [unknown](https://github.com/BobTheBuidler/faster-async-lru/blob/renovate/compile-pytest-cov-7.x/unknown) - [view benchmarks](https://github.com/BobTheBuidler/faster-async-lru/blob/renovate/compile-pytest-cov-7.x/unknown)

| Function | Reference Mean | Faster Mean | % Change | Speedup (%) | x Faster | Faster |
|----------|---------------|-------------|----------|-------------|----------|--------|
| `cache_clear_benchmark[bounded]` | 5.65187548652578e-07 | 3.997028074316642e-07 | 29.28% | 41.40% | 1.41x | ✅ |
| `cache_clear_benchmark[meth-bounded]` | 6.11550010366442e-07 | 4.0067495074043603e-07 | 34.48% | 52.63% | 1.53x | ✅ |
| `cache_clear_benchmark[meth-unbounded]` | 6.046145376940535e-07 | 4.019176103106771e-07 | 33.52% | 50.43% | 1.50x | ✅ |
| `cache_clear_benchmark[unbounded]` | 5.64234210408303e-07 | 4.014918084263268e-07 | 28.84% | 40.53% | 1.41x | ✅ |
| `cache_fill_eviction_benchmark` | 0.090937868545454 | 0.08388884441666751 | 7.75% | 8.40% | 1.08x | ✅ |
| `cache_hit_benchmark[bounded]` | 0.0010342332608692004 | 0.000562667540636026 | 45.60% | 83.81% | 1.84x | ✅ |
| `cache_hit_benchmark[meth-bounded]` | 0.0015725449699371516 | 0.0017773854262297295 | -13.03% | -11.52% | 0.88x | ❌ |
| `cache_hit_benchmark[meth-unbounded]` | 0.0015747505935483593 | 0.0017567262353986634 | -11.56% | -10.36% | 0.90x | ❌ |
| `cache_hit_benchmark[unbounded]` | 0.0010414743044871724 | 0.0005614414029512456 | 46.09% | 85.50% | 1.86x | ✅ |
| `cache_info_benchmark[bounded]` | 0.0004926521286520773 | 0.0003829993904680648 | 22.26% | 28.63% | 1.29x | ✅ |
| `cache_info_benchmark[meth-bounded]` | 0.0005418007493053849 | 0.00038617179473661456 | 28.72% | 40.30% | 1.40x | ✅ |
| `cache_info_benchmark[meth-unbounded]` | 0.000541736996755041 | 0.0003822446290448503 | 29.44% | 41.73% | 1.42x | ✅ |
| `cache_info_benchmark[unbounded]` | 0.0004925855400198825 | 0.0003765451166992862 | 23.56% | 30.82% | 1.31x | ✅ |
| `cache_invalidate_benchmark[bounded]` | 7.431771106763962e-05 | 2.9782745162475544e-05 | 59.93% | 149.53% | 2.50x | ✅ |
| `cache_invalidate_benchmark[meth-bounded]` | 0.0001564991827249911 | 0.00019650915368126597 | -25.57% | -20.36% | 0.80x | ❌ |
| `cache_invalidate_benchmark[meth-unbounded]` | 0.0001547787043420943 | 0.00019663964104649423 | -27.05% | -21.29% | 0.79x | ❌ |
| `cache_invalidate_benchmark[unbounded]` | 7.477049261204011e-05 | 2.9027079986197392e-05 | 61.18% | 157.59% | 2.58x | ✅ |
| `cache_miss_benchmark[bounded]` | 0.00015088111463422513 | 0.00018087747880338807 | -19.88% | -16.58% | 0.83x | ❌ |
| `cache_miss_benchmark[meth-bounded]` | 0.0002148267888046477 | 0.00024073760506359025 | -12.06% | -10.76% | 0.89x | ❌ |
| `cache_miss_benchmark[meth-unbounded]` | 0.00021419621994897062 | 0.00024172557179374856 | -12.85% | -11.39% | 0.89x | ❌ |
| `cache_miss_benchmark[unbounded]` | 0.00015376725980429211 | 0.0001807050782406044 | -17.52% | -14.91% | 0.85x | ❌ |
| `cache_ttl_expiry_benchmark[bounded]` | 1.1860247326894516e-05 | 1.1147830525991848e-05 | 6.01% | 6.39% | 1.06x | ✅ |
| `cache_ttl_expiry_benchmark[meth-bounded]` | 1.2611867150044389e-05 | 1.3247219697978928e-05 | -5.04% | -4.80% | 0.95x | ❌ |
| `cache_ttl_expiry_benchmark[meth-unbounded]` | 1.2714238417219227e-05 | 1.3297427411477885e-05 | -4.59% | -4.39% | 0.96x | ❌ |
| `cache_ttl_expiry_benchmark[unbounded]` | 1.2267960661206794e-05 | 1.1156551447854271e-05 | 9.06% | 9.96% | 1.10x | ✅ |
| `concurrent_cache_hit_benchmark[bounded]` | 0.0004769552985614024 | 0.0004235400906650049 | 11.20% | 12.61% | 1.13x | ✅ |
| `concurrent_cache_hit_benchmark[meth-bounded]` | 0.0005361720298678596 | 0.000571254204044149 | -6.54% | -6.14% | 0.94x | ❌ |
| `concurrent_cache_hit_benchmark[meth-unbounded]` | 0.0005387879821997481 | 0.0005623378240915192 | -4.37% | -4.19% | 0.96x | ❌ |
| `concurrent_cache_hit_benchmark[unbounded]` | 0.000474759566908777 | 0.0004239145843171974 | 10.71% | 11.99% | 1.12x | ✅ |
| `internal_cache_hit_microbenchmark[bounded]` | 2.5529079216650955e-05 | 9.631170612342659e-06 | 62.27% | 165.07% | 2.65x | ✅ |
| `internal_cache_hit_microbenchmark[unbounded]` | 2.537812832595264e-05 | 9.5839799968345e-06 | 62.24% | 164.80% | 2.65x | ✅ |
| `internal_cache_miss_microbenchmark[bounded]` | 1.398306833646229e-05 | 3.4660036869371055e-06 | 75.21% | 303.43% | 4.03x | ✅ |
| `internal_cache_miss_microbenchmark[unbounded]` | 1.4044703847431332e-05 | 3.4262518081654855e-06 | 75.60% | 309.91% | 4.10x | ✅ |
| `internal_task_done_callback_microbenchmark[cancelled-bounded]` | 0.00014642716321942544 | 0.00010752611556571349 | 26.57% | 36.18% | 1.36x | ✅ |
| `internal_task_done_callback_microbenchmark[cancelled-unbounded]` | 0.00014736064296768953 | 0.00010934937618880122 | 25.79% | 34.76% | 1.35x | ✅ |
| `internal_task_done_callback_microbenchmark[exception-bounded]` | 0.00017802779812755144 | 0.00013281726928282233 | 25.40% | 34.04% | 1.34x | ✅ |
| `internal_task_done_callback_microbenchmark[exception-unbounded]` | 0.00018033577248014016 | 0.00013453045461979984 | 25.40% | 34.05% | 1.34x | ✅ |
| `internal_task_done_callback_microbenchmark[finished-bounded]` | 0.00020926998177859724 | 0.00012927521944295148 | 38.23% | 61.88% | 1.62x | ✅ |
| `internal_task_done_callback_microbenchmark[finished-unbounded]` | 0.0002092635444064374 | 0.00012915294611076273 | 38.28% | 62.03% | 1.62x | ✅ |
