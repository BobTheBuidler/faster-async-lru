#### [unknown](https://github.com/BobTheBuidler/faster-async-lru/blob/renovate/compile-pytest-benchmark-5.x/unknown) - [view benchmarks](https://github.com/BobTheBuidler/faster-async-lru/blob/renovate/compile-pytest-benchmark-5.x/unknown)

| Function | Reference Mean | Faster Mean | % Change | Speedup (%) | x Faster | Faster |
|----------|---------------|-------------|----------|-------------|----------|--------|
| `cache_clear_benchmark[bounded]` | 5.666193669022131e-07 | 4.043154270591331e-07 | 28.64% | 40.14% | 1.40x | ✅ |
| `cache_clear_benchmark[meth-bounded]` | 6.082742095514614e-07 | 4.1456313648357245e-07 | 31.85% | 46.73% | 1.47x | ✅ |
| `cache_clear_benchmark[meth-unbounded]` | 6.038567475629286e-07 | 4.1271663040018586e-07 | 31.65% | 46.31% | 1.46x | ✅ |
| `cache_clear_benchmark[unbounded]` | 5.66769087516173e-07 | 3.9788303175909986e-07 | 29.80% | 42.45% | 1.42x | ✅ |
| `cache_fill_eviction_benchmark` | 0.09156707409091135 | 0.08525748550000027 | 6.89% | 7.40% | 1.07x | ✅ |
| `cache_hit_benchmark[bounded]` | 0.0010519308727062963 | 0.0005832898046045685 | 44.55% | 80.34% | 1.80x | ✅ |
| `cache_hit_benchmark[meth-bounded]` | 0.0016338574983820727 | 0.001806618981751955 | -10.57% | -9.56% | 0.90x | ❌ |
| `cache_hit_benchmark[meth-unbounded]` | 0.0016175441184208726 | 0.0018099590723328139 | -11.90% | -10.63% | 0.89x | ❌ |
| `cache_hit_benchmark[unbounded]` | 0.0010574408054645583 | 0.0005878748563537089 | 44.41% | 79.88% | 1.80x | ✅ |
| `cache_info_benchmark[bounded]` | 0.0004870993560724255 | 0.0003779853378544427 | 22.40% | 28.87% | 1.29x | ✅ |
| `cache_info_benchmark[meth-bounded]` | 0.0005398588445331952 | 0.0003868445154521642 | 28.34% | 39.55% | 1.40x | ✅ |
| `cache_info_benchmark[meth-unbounded]` | 0.0005331819930666597 | 0.0003854383905236702 | 27.71% | 38.33% | 1.38x | ✅ |
| `cache_info_benchmark[unbounded]` | 0.0004887626207233137 | 0.00038051160717045437 | 22.15% | 28.45% | 1.28x | ✅ |
| `cache_invalidate_benchmark[bounded]` | 7.543477729135422e-05 | 2.643666379039487e-05 | 64.95% | 185.34% | 2.85x | ✅ |
| `cache_invalidate_benchmark[meth-bounded]` | 0.0001517149451192934 | 0.00019947004635943911 | -31.48% | -23.94% | 0.76x | ❌ |
| `cache_invalidate_benchmark[meth-unbounded]` | 0.00015031733249849298 | 0.0002005698146779135 | -33.43% | -25.05% | 0.75x | ❌ |
| `cache_invalidate_benchmark[unbounded]` | 7.514588969295772e-05 | 2.6724678944963747e-05 | 64.44% | 181.19% | 2.81x | ✅ |
| `cache_miss_benchmark[bounded]` | 0.00015545602046049687 | 0.00018451480208373874 | -18.69% | -15.75% | 0.84x | ❌ |
| `cache_miss_benchmark[meth-bounded]` | 0.0002167412164182712 | 0.00024561759189187135 | -13.32% | -11.76% | 0.88x | ❌ |
| `cache_miss_benchmark[meth-unbounded]` | 0.00021771987657402613 | 0.0002468602520321806 | -13.38% | -11.80% | 0.88x | ❌ |
| `cache_miss_benchmark[unbounded]` | 0.00017022497969516705 | 0.00018350474489738287 | -7.80% | -7.24% | 0.93x | ❌ |
| `cache_ttl_expiry_benchmark[bounded]` | 1.1799612053346058e-05 | 1.1003957951701592e-05 | 6.74% | 7.23% | 1.07x | ✅ |
| `cache_ttl_expiry_benchmark[meth-bounded]` | 1.2320461514186807e-05 | 1.3386166500863766e-05 | -8.65% | -7.96% | 0.92x | ❌ |
| `cache_ttl_expiry_benchmark[meth-unbounded]` | 1.2374645100550758e-05 | 1.318213950418145e-05 | -6.53% | -6.13% | 0.94x | ❌ |
| `cache_ttl_expiry_benchmark[unbounded]` | 1.2246542844456892e-05 | 1.0974497477486394e-05 | 10.39% | 11.59% | 1.12x | ✅ |
| `concurrent_cache_hit_benchmark[bounded]` | 0.0004793721926308853 | 0.0004307978218923161 | 10.13% | 11.28% | 1.11x | ✅ |
| `concurrent_cache_hit_benchmark[meth-bounded]` | 0.0005383545610464027 | 0.0005690023932225837 | -5.69% | -5.39% | 0.95x | ❌ |
| `concurrent_cache_hit_benchmark[meth-unbounded]` | 0.0005454859982163152 | 0.0005698623677380516 | -4.47% | -4.28% | 0.96x | ❌ |
| `concurrent_cache_hit_benchmark[unbounded]` | 0.00047546371517344225 | 0.0004272442488708711 | 10.14% | 11.29% | 1.11x | ✅ |
| `internal_cache_hit_microbenchmark[bounded]` | 2.5238468314154747e-05 | 9.705063554863486e-06 | 61.55% | 160.05% | 2.60x | ✅ |
| `internal_cache_hit_microbenchmark[unbounded]` | 2.527679654865573e-05 | 9.602689654815681e-06 | 62.01% | 163.23% | 2.63x | ✅ |
| `internal_cache_miss_microbenchmark[bounded]` | 1.4764968961421795e-05 | 3.4446944170271807e-06 | 76.67% | 328.63% | 4.29x | ✅ |
| `internal_cache_miss_microbenchmark[unbounded]` | 1.4995651964857938e-05 | 3.4845132495137877e-06 | 76.76% | 330.35% | 4.30x | ✅ |
| `internal_task_done_callback_microbenchmark[cancelled-bounded]` | 0.00014962896533107548 | 0.00011015274818398803 | 26.38% | 35.84% | 1.36x | ✅ |
| `internal_task_done_callback_microbenchmark[cancelled-unbounded]` | 0.0001474328453317954 | 0.00010851319228739145 | 26.40% | 35.87% | 1.36x | ✅ |
| `internal_task_done_callback_microbenchmark[exception-bounded]` | 0.0001779906010859336 | 0.00013504411233201472 | 24.13% | 31.80% | 1.32x | ✅ |
| `internal_task_done_callback_microbenchmark[exception-unbounded]` | 0.00018010818455627893 | 0.00013486039418639234 | 25.12% | 33.55% | 1.34x | ✅ |
| `internal_task_done_callback_microbenchmark[finished-bounded]` | 0.00021764969486326113 | 0.00012591501324318266 | 42.15% | 72.85% | 1.73x | ✅ |
| `internal_task_done_callback_microbenchmark[finished-unbounded]` | 0.0002164977138827945 | 0.0001272879828401847 | 41.21% | 70.08% | 1.70x | ✅ |
