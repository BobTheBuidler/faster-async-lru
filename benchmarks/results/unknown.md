#### [unknown](https://github.com/BobTheBuidler/faster-async-lru/blob/fix/bench-compile-20260217163213/unknown) - [view benchmarks](https://github.com/BobTheBuidler/faster-async-lru/blob/fix/bench-compile-20260217163213/unknown)

| Function | Reference Mean | Faster Mean | % Change | Speedup (%) | x Faster | Faster |
|----------|---------------|-------------|----------|-------------|----------|--------|
| `cache_clear_benchmark[bounded]` | 6.023623476345727e-07 | 3.938706449555447e-07 | 34.61% | 52.93% | 1.53x | ✅ |
| `cache_clear_benchmark[meth-bounded]` | 6.356965077296251e-07 | 4.0596856903140097e-07 | 36.14% | 56.59% | 1.57x | ✅ |
| `cache_clear_benchmark[meth-unbounded]` | 6.399454457251329e-07 | 4.0430169037435656e-07 | 36.82% | 58.28% | 1.58x | ✅ |
| `cache_clear_benchmark[unbounded]` | 6.22100462857649e-07 | 3.9560512268618453e-07 | 36.41% | 57.25% | 1.57x | ✅ |
| `cache_fill_eviction_benchmark` | 0.10019337830000126 | 0.08352992266666585 | 16.63% | 19.95% | 1.20x | ✅ |
| `cache_hit_benchmark[bounded]` | 0.001061216944757675 | 0.000591738950992359 | 44.24% | 79.34% | 1.79x | ✅ |
| `cache_hit_benchmark[meth-bounded]` | 0.001618955718698605 | 0.001851562058607886 | -14.37% | -12.56% | 0.87x | ❌ |
| `cache_hit_benchmark[meth-unbounded]` | 0.0016183662442997005 | 0.0018235052370368923 | -12.68% | -11.25% | 0.89x | ❌ |
| `cache_hit_benchmark[unbounded]` | 0.0010822683726364288 | 0.0006069395352293568 | 43.92% | 78.32% | 1.78x | ✅ |
| `cache_info_benchmark[bounded]` | 0.0004869530427564768 | 0.0003783441077990734 | 22.30% | 28.71% | 1.29x | ✅ |
| `cache_info_benchmark[meth-bounded]` | 0.0005352027691048272 | 0.00038436540879521226 | 28.18% | 39.24% | 1.39x | ✅ |
| `cache_info_benchmark[meth-unbounded]` | 0.0005285326165611708 | 0.00038398376797778457 | 27.35% | 37.64% | 1.38x | ✅ |
| `cache_info_benchmark[unbounded]` | 0.00049006684573128 | 0.00037734848398439657 | 23.00% | 29.87% | 1.30x | ✅ |
| `cache_invalidate_benchmark[bounded]` | 7.36884902981878e-05 | 2.6995313570048946e-05 | 63.37% | 172.97% | 2.73x | ✅ |
| `cache_invalidate_benchmark[meth-bounded]` | 0.00015084565576460314 | 0.00019573428571419686 | -29.76% | -22.93% | 0.77x | ❌ |
| `cache_invalidate_benchmark[meth-unbounded]` | 0.00015031978552072263 | 0.0001962790652287157 | -30.57% | -23.42% | 0.77x | ❌ |
| `cache_invalidate_benchmark[unbounded]` | 7.329123980308346e-05 | 2.6952990710883992e-05 | 63.22% | 171.92% | 2.72x | ✅ |
| `cache_miss_benchmark[bounded]` | 0.00015578346301391814 | 0.00018668440966911783 | -19.84% | -16.55% | 0.83x | ❌ |
| `cache_miss_benchmark[meth-bounded]` | 0.000222124019774096 | 0.00024370071087525988 | -9.71% | -8.85% | 0.91x | ❌ |
| `cache_miss_benchmark[meth-unbounded]` | 0.0002194302045458149 | 0.0002455606287266633 | -11.91% | -10.64% | 0.89x | ❌ |
| `cache_miss_benchmark[unbounded]` | 0.0001602163360434568 | 0.00018370184318760511 | -14.66% | -12.78% | 0.87x | ❌ |
| `cache_ttl_expiry_benchmark[bounded]` | 1.1698960780665217e-05 | 1.0919400990420335e-05 | 6.66% | 7.14% | 1.07x | ✅ |
| `cache_ttl_expiry_benchmark[meth-bounded]` | 1.2398318559207478e-05 | 1.3047919836767551e-05 | -5.24% | -4.98% | 0.95x | ❌ |
| `cache_ttl_expiry_benchmark[meth-unbounded]` | 1.2311328087113251e-05 | 1.3052332358284218e-05 | -6.02% | -5.68% | 0.94x | ❌ |
| `cache_ttl_expiry_benchmark[unbounded]` | 1.1650692117690935e-05 | 1.087515899924694e-05 | 6.66% | 7.13% | 1.07x | ✅ |
| `concurrent_cache_hit_benchmark[bounded]` | 0.0004773741286511619 | 0.0004357452200363895 | 8.72% | 9.55% | 1.10x | ✅ |
| `concurrent_cache_hit_benchmark[meth-bounded]` | 0.0005421845907474198 | 0.0005672880724198862 | -4.63% | -4.43% | 0.96x | ❌ |
| `concurrent_cache_hit_benchmark[meth-unbounded]` | 0.0005405998835340319 | 0.0005728030318021604 | -5.96% | -5.62% | 0.94x | ❌ |
| `concurrent_cache_hit_benchmark[unbounded]` | 0.00047804330472571736 | 0.00042364395068867787 | 11.38% | 12.84% | 1.13x | ✅ |
| `internal_cache_hit_microbenchmark[bounded]` | 2.5508130700026716e-05 | 9.613988166162211e-06 | 62.31% | 165.32% | 2.65x | ✅ |
| `internal_cache_hit_microbenchmark[unbounded]` | 2.5229390228869277e-05 | 9.464927981106516e-06 | 62.48% | 166.56% | 2.67x | ✅ |
| `internal_cache_miss_microbenchmark[bounded]` | 1.3825199204307754e-05 | 3.390923084377208e-06 | 75.47% | 307.71% | 4.08x | ✅ |
| `internal_cache_miss_microbenchmark[unbounded]` | 1.3865943422131461e-05 | 3.3110292751195025e-06 | 76.12% | 318.78% | 4.19x | ✅ |
| `internal_task_done_callback_microbenchmark[cancelled-bounded]` | 0.0005525588411383202 | 0.00010922894062711243 | 80.23% | 405.87% | 5.06x | ✅ |
| `internal_task_done_callback_microbenchmark[cancelled-unbounded]` | 0.0005489461170343964 | 0.00010826030578651643 | 80.28% | 407.06% | 5.07x | ✅ |
| `internal_task_done_callback_microbenchmark[exception-bounded]` | 0.3873759354000043 | 0.00013335262017484948 | 99.97% | 290389.93% | 2904.90x | ✅ |
| `internal_task_done_callback_microbenchmark[exception-unbounded]` | 0.3824123261999972 | 0.0001340977895165139 | 99.96% | 285074.22% | 2851.74x | ✅ |
| `internal_task_done_callback_microbenchmark[finished-bounded]` | 0.0006398118877164599 | 0.00013308329685068226 | 79.20% | 380.76% | 4.81x | ✅ |
| `internal_task_done_callback_microbenchmark[finished-unbounded]` | 0.0006347944548968863 | 0.00013587857563022196 | 78.59% | 367.18% | 4.67x | ✅ |
