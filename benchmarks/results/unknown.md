#### [unknown](https://github.com/BobTheBuidler/faster-async-lru/blob/renovate/compile-async-lru-2.x/unknown) - [view benchmarks](https://github.com/BobTheBuidler/faster-async-lru/blob/renovate/compile-async-lru-2.x/unknown)

| Function | Reference Mean | Faster Mean | % Change | Speedup (%) | x Faster | Faster |
|----------|---------------|-------------|----------|-------------|----------|--------|
| `cache_clear_benchmark[bounded]` | 5.002984722250485e-07 | 3.648166089805865e-07 | 27.08% | 37.14% | 1.37x | ✅ |
| `cache_clear_benchmark[meth-bounded]` | 5.47458327397981e-07 | 3.644424805365394e-07 | 33.43% | 50.22% | 1.50x | ✅ |
| `cache_clear_benchmark[meth-unbounded]` | 5.505128780757976e-07 | 3.6768325733499674e-07 | 33.21% | 49.72% | 1.50x | ✅ |
| `cache_clear_benchmark[unbounded]` | 5.005888804735262e-07 | 3.6252877611101676e-07 | 27.58% | 38.08% | 1.38x | ✅ |
| `cache_fill_eviction_benchmark` | 0.07020668786666799 | 0.06625027518750493 | 5.64% | 5.97% | 1.06x | ✅ |
| `cache_hit_benchmark[bounded]` | 0.0010154957058824477 | 0.00047426446956062634 | 53.30% | 114.12% | 2.14x | ✅ |
| `cache_hit_benchmark[meth-bounded]` | 0.0015585585141506485 | 0.0016664254557828323 | -6.92% | -6.47% | 0.94x | ❌ |
| `cache_hit_benchmark[meth-unbounded]` | 0.0015454394120438754 | 0.0017118770359066408 | -10.77% | -9.72% | 0.90x | ❌ |
| `cache_hit_benchmark[unbounded]` | 0.001015679731000148 | 0.00047526596734668485 | 53.21% | 113.71% | 2.14x | ✅ |
| `cache_info_benchmark[bounded]` | 0.0004437966996571999 | 0.00035895279098842727 | 19.12% | 23.64% | 1.24x | ✅ |
| `cache_info_benchmark[meth-bounded]` | 0.0004847580541768999 | 0.0003584456980591076 | 26.06% | 35.24% | 1.35x | ✅ |
| `cache_info_benchmark[meth-unbounded]` | 0.000491028624937792 | 0.0003586718773446891 | 26.95% | 36.90% | 1.37x | ✅ |
| `cache_info_benchmark[unbounded]` | 0.00044593072968135915 | 0.0003567625173410578 | 20.00% | 24.99% | 1.25x | ✅ |
| `cache_invalidate_benchmark[bounded]` | 6.963128796407236e-05 | 2.4787253699283585e-05 | 64.40% | 180.92% | 2.81x | ✅ |
| `cache_invalidate_benchmark[meth-bounded]` | 0.0001390814118451322 | 0.00017314267546105543 | -24.49% | -19.67% | 0.80x | ❌ |
| `cache_invalidate_benchmark[meth-unbounded]` | 0.00013804949151919455 | 0.0001733824916013537 | -25.59% | -20.38% | 0.80x | ❌ |
| `cache_invalidate_benchmark[unbounded]` | 6.942961123258694e-05 | 2.4805680453142014e-05 | 64.27% | 179.89% | 2.80x | ✅ |
| `cache_miss_benchmark[bounded]` | 0.00013945771755755342 | 0.00015680212280704477 | -12.44% | -11.06% | 0.89x | ❌ |
| `cache_miss_benchmark[meth-bounded]` | 0.0002033795338484751 | 0.00022509804233922774 | -10.68% | -9.65% | 0.90x | ❌ |
| `cache_miss_benchmark[meth-unbounded]` | 0.00020678099606249715 | 0.00023213230460926356 | -12.26% | -10.92% | 0.89x | ❌ |
| `cache_miss_benchmark[unbounded]` | 0.0001394875286261798 | 0.00015662379457392819 | -12.29% | -10.94% | 0.89x | ❌ |
| `cache_ttl_expiry_benchmark[bounded]` | 8.940696115957274e-06 | 8.49566067065283e-06 | 4.98% | 5.24% | 1.05x | ✅ |
| `cache_ttl_expiry_benchmark[meth-bounded]` | 1.0081107123323574e-05 | 1.0075838380463258e-05 | 0.05% | 0.05% | 1.00x | ✅ |
| `cache_ttl_expiry_benchmark[meth-unbounded]` | 9.491675611462755e-06 | 1.0187107152883105e-05 | -7.33% | -6.83% | 0.93x | ❌ |
| `cache_ttl_expiry_benchmark[unbounded]` | 8.853136544840345e-06 | 8.425317736679974e-06 | 4.83% | 5.08% | 1.05x | ✅ |
| `concurrent_cache_hit_benchmark[bounded]` | 0.00041197302720296963 | 0.0003670540914134812 | 10.90% | 12.24% | 1.12x | ✅ |
| `concurrent_cache_hit_benchmark[meth-bounded]` | 0.00046052009344404283 | 0.00048557081328234295 | -5.44% | -5.16% | 0.95x | ❌ |
| `concurrent_cache_hit_benchmark[meth-unbounded]` | 0.00046287879144896166 | 0.0004857929686505641 | -4.95% | -4.72% | 0.95x | ❌ |
| `concurrent_cache_hit_benchmark[unbounded]` | 0.0004105302861027715 | 0.00036611543195265314 | 10.82% | 12.13% | 1.12x | ✅ |
| `internal_cache_hit_microbenchmark[bounded]` | 2.4118569665859947e-05 | 8.02843536597665e-06 | 66.71% | 200.41% | 3.00x | ✅ |
| `internal_cache_hit_microbenchmark[unbounded]` | 2.410844866256467e-05 | 8.03695587995857e-06 | 66.66% | 199.97% | 3.00x | ✅ |
| `internal_cache_miss_microbenchmark[bounded]` | 1.2990695231554907e-05 | 3.145396971860421e-06 | 75.79% | 313.01% | 4.13x | ✅ |
| `internal_cache_miss_microbenchmark[unbounded]` | 1.2731076206246382e-05 | 3.0712497759618217e-06 | 75.88% | 314.52% | 4.15x | ✅ |
| `internal_task_done_callback_microbenchmark[cancelled-bounded]` | 0.00013201978343263982 | 0.00010117933730926577 | 23.36% | 30.48% | 1.30x | ✅ |
| `internal_task_done_callback_microbenchmark[cancelled-unbounded]` | 0.000132438265773002 | 0.00010129535210691757 | 23.52% | 30.74% | 1.31x | ✅ |
| `internal_task_done_callback_microbenchmark[exception-bounded]` | 0.00016191195346872478 | 0.00012916417941969354 | 20.23% | 25.35% | 1.25x | ✅ |
| `internal_task_done_callback_microbenchmark[exception-unbounded]` | 0.00016082392368347236 | 0.00012907764680399818 | 19.74% | 24.59% | 1.25x | ✅ |
| `internal_task_done_callback_microbenchmark[finished-bounded]` | 0.000204032106272123 | 0.0001100078394307127 | 46.08% | 85.47% | 1.85x | ✅ |
| `internal_task_done_callback_microbenchmark[finished-unbounded]` | 0.0002038434233688086 | 0.00011022933641348757 | 45.92% | 84.93% | 1.85x | ✅ |
