#### [unknown](https://github.com/BobTheBuidler/faster-async-lru/blob/compile/unknown) - [view benchmarks](https://github.com/BobTheBuidler/faster-async-lru/blob/compile/unknown)

| Function | Reference Mean | Faster Mean | % Change | Speedup (%) | x Faster | Faster |
|----------|---------------|-------------|----------|-------------|----------|--------|
| `cache_clear_benchmark[bounded]` | 5.671011501159636e-07 | 3.970117016390361e-07 | 29.99% | 42.84% | 1.43x | ✅ |
| `cache_clear_benchmark[meth-bounded]` | 6.170841858432159e-07 | 3.93801590436374e-07 | 36.18% | 56.70% | 1.57x | ✅ |
| `cache_clear_benchmark[meth-unbounded]` | 6.223897006497388e-07 | 3.945833525818697e-07 | 36.60% | 57.73% | 1.58x | ✅ |
| `cache_clear_benchmark[unbounded]` | 5.658366627455461e-07 | 4.0561660037465003e-07 | 28.32% | 39.50% | 1.40x | ✅ |
| `cache_fill_eviction_benchmark` | 0.09010315383333396 | 0.08287543915384586 | 8.02% | 8.72% | 1.09x | ✅ |
| `cache_hit_benchmark[bounded]` | 0.0010234251817192606 | 0.0005367062035857701 | 47.56% | 90.69% | 1.91x | ✅ |
| `cache_hit_benchmark[meth-bounded]` | 0.0015463413459715608 | 0.0017995202069599103 | -16.37% | -14.07% | 0.86x | ❌ |
| `cache_hit_benchmark[meth-unbounded]` | 0.0015432495102684002 | 0.00177068851075265 | -14.74% | -12.84% | 0.87x | ❌ |
| `cache_hit_benchmark[unbounded]` | 0.0010297179572366965 | 0.0005323424647507602 | 48.30% | 93.43% | 1.93x | ✅ |
| `cache_info_benchmark[bounded]` | 0.0004941779708222363 | 0.000389203855888043 | 21.24% | 26.97% | 1.27x | ✅ |
| `cache_info_benchmark[meth-bounded]` | 0.0005378415154060834 | 0.00038742837107657376 | 27.97% | 38.82% | 1.39x | ✅ |
| `cache_info_benchmark[meth-unbounded]` | 0.0005398054140407427 | 0.0003888161766813462 | 27.97% | 38.83% | 1.39x | ✅ |
| `cache_info_benchmark[unbounded]` | 0.0004911268064031701 | 0.00038454054853286095 | 21.70% | 27.72% | 1.28x | ✅ |
| `cache_invalidate_benchmark[bounded]` | 7.399927835191549e-05 | 2.992576798194972e-05 | 59.56% | 147.28% | 2.47x | ✅ |
| `cache_invalidate_benchmark[meth-bounded]` | 0.0001542464451995182 | 0.000191546486034993 | -24.18% | -19.47% | 0.81x | ❌ |
| `cache_invalidate_benchmark[meth-unbounded]` | 0.00015452122780100567 | 0.00019656375178435533 | -27.21% | -21.39% | 0.79x | ❌ |
| `cache_invalidate_benchmark[unbounded]` | 7.511571267967354e-05 | 2.996280331547052e-05 | 60.11% | 150.70% | 2.51x | ✅ |
| `cache_miss_benchmark[bounded]` | 0.00014852624029129167 | 0.0001784161043260998 | -20.12% | -16.75% | 0.83x | ❌ |
| `cache_miss_benchmark[meth-bounded]` | 0.000211185540145572 | 0.00023868451851861828 | -13.02% | -11.52% | 0.88x | ❌ |
| `cache_miss_benchmark[meth-unbounded]` | 0.0002124344149999402 | 0.00023997698157851227 | -12.97% | -11.48% | 0.89x | ❌ |
| `cache_miss_benchmark[unbounded]` | 0.0001496329180328536 | 0.00024278670135744685 | -62.25% | -38.37% | 0.62x | ❌ |
| `cache_ttl_expiry_benchmark[bounded]` | 1.1636702229095865e-05 | 1.0876652620299382e-05 | 6.53% | 6.99% | 1.07x | ✅ |
| `cache_ttl_expiry_benchmark[meth-bounded]` | 1.2524180164950308e-05 | 1.2756164300894577e-05 | -1.85% | -1.82% | 0.98x | ❌ |
| `cache_ttl_expiry_benchmark[meth-unbounded]` | 1.2475015673479262e-05 | 1.2764883075422513e-05 | -2.32% | -2.27% | 0.98x | ❌ |
| `cache_ttl_expiry_benchmark[unbounded]` | 1.1933419637857526e-05 | 1.0935928565954847e-05 | 8.36% | 9.12% | 1.09x | ✅ |
| `concurrent_cache_hit_benchmark[bounded]` | 0.0004808549344466599 | 0.00042743250862955844 | 11.11% | 12.50% | 1.12x | ✅ |
| `concurrent_cache_hit_benchmark[meth-bounded]` | 0.0005356320538228099 | 0.0005617601074028462 | -4.88% | -4.65% | 0.95x | ❌ |
| `concurrent_cache_hit_benchmark[meth-unbounded]` | 0.0005375168014750445 | 0.0005624094210527475 | -4.63% | -4.43% | 0.96x | ❌ |
| `concurrent_cache_hit_benchmark[unbounded]` | 0.0004814401183372731 | 0.0004272584161464865 | 11.25% | 12.68% | 1.13x | ✅ |
| `internal_cache_hit_microbenchmark[bounded]` | 2.6573776369427427e-05 | 9.87741421263822e-06 | 62.83% | 169.04% | 2.69x | ✅ |
| `internal_cache_hit_microbenchmark[unbounded]` | 2.6107923737462013e-05 | 9.803253552538219e-06 | 62.45% | 166.32% | 2.66x | ✅ |
| `internal_cache_miss_microbenchmark[bounded]` | 1.4645672203676556e-05 | 3.6667581126060155e-06 | 74.96% | 299.42% | 3.99x | ✅ |
| `internal_cache_miss_microbenchmark[unbounded]` | 1.4619500625912245e-05 | 3.8211723751602715e-06 | 73.86% | 282.59% | 3.83x | ✅ |
| `internal_task_done_callback_microbenchmark[cancelled-bounded]` | 0.00014984804860637962 | 0.00010847807027999225 | 27.61% | 38.14% | 1.38x | ✅ |
| `internal_task_done_callback_microbenchmark[cancelled-unbounded]` | 0.0001489565098661586 | 0.00010935938205839408 | 26.58% | 36.21% | 1.36x | ✅ |
| `internal_task_done_callback_microbenchmark[exception-bounded]` | 0.00017785363491410413 | 0.00013191847963180977 | 25.83% | 34.82% | 1.35x | ✅ |
| `internal_task_done_callback_microbenchmark[exception-unbounded]` | 0.00017811292795030039 | 0.00013537278066971152 | 24.00% | 31.57% | 1.32x | ✅ |
| `internal_task_done_callback_microbenchmark[finished-bounded]` | 0.00020820631864409346 | 0.00012806550997110187 | 38.49% | 62.58% | 1.63x | ✅ |
| `internal_task_done_callback_microbenchmark[finished-unbounded]` | 0.00020958971328227435 | 0.00012834931261348012 | 38.76% | 63.30% | 1.63x | ✅ |
