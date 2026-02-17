#### [unknown](https://github.com/BobTheBuidler/faster-async-lru/blob/fix/bench-compile-20260217163213/unknown) - [view benchmarks](https://github.com/BobTheBuidler/faster-async-lru/blob/fix/bench-compile-20260217163213/unknown)

| Function | Reference Mean | Faster Mean | % Change | Speedup (%) | x Faster | Faster |
|----------|---------------|-------------|----------|-------------|----------|--------|
| `cache_clear_benchmark[bounded]` | 6.243734236357188e-07 | 4.1353048742220335e-07 | 33.77% | 50.99% | 1.51x | ✅ |
| `cache_clear_benchmark[meth-bounded]` | 6.632250442532198e-07 | 4.1971590588724337e-07 | 36.72% | 58.02% | 1.58x | ✅ |
| `cache_clear_benchmark[meth-unbounded]` | 6.652709687217798e-07 | 4.2089190501756067e-07 | 36.73% | 58.06% | 1.58x | ✅ |
| `cache_clear_benchmark[unbounded]` | 6.176953106726132e-07 | 4.1242632908364203e-07 | 33.23% | 49.77% | 1.50x | ✅ |
| `cache_fill_eviction_benchmark` | 0.10128454510000325 | 0.08441933000000763 | 16.65% | 19.98% | 1.20x | ✅ |
| `cache_hit_benchmark[bounded]` | 0.001052108928813801 | 0.0005737087884376527 | 45.47% | 83.39% | 1.83x | ✅ |
| `cache_hit_benchmark[meth-bounded]` | 0.0015603569305999577 | 0.001839897276951457 | -17.92% | -15.19% | 0.85x | ❌ |
| `cache_hit_benchmark[meth-unbounded]` | 0.0015548201815334694 | 0.0018228408701302062 | -17.24% | -14.70% | 0.85x | ❌ |
| `cache_hit_benchmark[unbounded]` | 0.0010412788605875022 | 0.0005812476306925675 | 44.18% | 79.15% | 1.79x | ✅ |
| `cache_info_benchmark[bounded]` | 0.000490903728317356 | 0.0003822632645411038 | 22.13% | 28.42% | 1.28x | ✅ |
| `cache_info_benchmark[meth-bounded]` | 0.0005294043234160095 | 0.00039446620567359345 | 25.49% | 34.21% | 1.34x | ✅ |
| `cache_info_benchmark[meth-unbounded]` | 0.0005378219650268623 | 0.0003843003524527522 | 28.55% | 39.95% | 1.40x | ✅ |
| `cache_info_benchmark[unbounded]` | 0.0004903404775139736 | 0.00038206885359893145 | 22.08% | 28.34% | 1.28x | ✅ |
| `cache_invalidate_benchmark[bounded]` | 7.490138529457543e-05 | 2.6871652830546966e-05 | 64.12% | 178.74% | 2.79x | ✅ |
| `cache_invalidate_benchmark[meth-bounded]` | 0.00015840016785387487 | 0.00020232641497829878 | -27.73% | -21.71% | 0.78x | ❌ |
| `cache_invalidate_benchmark[meth-unbounded]` | 0.00015765837530577458 | 0.00020583004127636926 | -30.55% | -23.40% | 0.77x | ❌ |
| `cache_invalidate_benchmark[unbounded]` | 7.439484188174961e-05 | 2.6890262806590795e-05 | 63.85% | 176.66% | 2.77x | ✅ |
| `cache_miss_benchmark[bounded]` | 0.00015378622752760694 | 0.00018275618734228777 | -18.84% | -15.85% | 0.84x | ❌ |
| `cache_miss_benchmark[meth-bounded]` | 0.00021224318994430942 | 0.0002492256236564877 | -17.42% | -14.84% | 0.85x | ❌ |
| `cache_miss_benchmark[meth-unbounded]` | 0.00021393485082862765 | 0.0002453451724145555 | -14.68% | -12.80% | 0.87x | ❌ |
| `cache_miss_benchmark[unbounded]` | 0.00015113498365132593 | 0.0001833663208021123 | -21.33% | -17.58% | 0.82x | ❌ |
| `cache_ttl_expiry_benchmark[bounded]` | 1.1782484688446159e-05 | 1.1121248904928224e-05 | 5.61% | 5.95% | 1.06x | ✅ |
| `cache_ttl_expiry_benchmark[meth-bounded]` | 1.2704545439199768e-05 | 1.3012974030467155e-05 | -2.43% | -2.37% | 0.98x | ❌ |
| `cache_ttl_expiry_benchmark[meth-unbounded]` | 1.25946481019668e-05 | 1.306477098176602e-05 | -3.73% | -3.60% | 0.96x | ❌ |
| `cache_ttl_expiry_benchmark[unbounded]` | 1.178897125564617e-05 | 1.1124646748998939e-05 | 5.64% | 5.97% | 1.06x | ✅ |
| `concurrent_cache_hit_benchmark[bounded]` | 0.0004903033919025745 | 0.0004357263376621413 | 11.13% | 12.53% | 1.13x | ✅ |
| `concurrent_cache_hit_benchmark[meth-bounded]` | 0.0005442094387174223 | 0.0005864188576576833 | -7.76% | -7.20% | 0.93x | ❌ |
| `concurrent_cache_hit_benchmark[meth-unbounded]` | 0.0005433884078711956 | 0.0005738604800232026 | -5.61% | -5.31% | 0.95x | ❌ |
| `concurrent_cache_hit_benchmark[unbounded]` | 0.0004904578495170537 | 0.00043205621763804766 | 11.91% | 13.52% | 1.14x | ✅ |
| `internal_cache_hit_microbenchmark[bounded]` | 2.6718185759022717e-05 | 9.61283103370486e-06 | 64.02% | 177.94% | 2.78x | ✅ |
| `internal_cache_hit_microbenchmark[unbounded]` | 2.6642422599395965e-05 | 9.68138122138577e-06 | 63.66% | 175.19% | 2.75x | ✅ |
| `internal_cache_miss_microbenchmark[bounded]` | 1.531909399769906e-05 | 3.7114637787503035e-06 | 75.77% | 312.75% | 4.13x | ✅ |
| `internal_cache_miss_microbenchmark[unbounded]` | 1.562827241855199e-05 | 3.5118682498177156e-06 | 77.53% | 345.01% | 4.45x | ✅ |
| `internal_task_done_callback_microbenchmark[cancelled-bounded]` | 0.0005749200093896648 | 0.0001115930011819996 | 80.59% | 415.19% | 5.15x | ✅ |
| `internal_task_done_callback_microbenchmark[cancelled-unbounded]` | 0.0005788382686945341 | 0.0001108492225684203 | 80.85% | 422.19% | 5.22x | ✅ |
| `internal_task_done_callback_microbenchmark[exception-bounded]` | 0.3964452424000058 | 0.00013792772607264185 | 99.97% | 287329.70% | 2874.30x | ✅ |
| `internal_task_done_callback_microbenchmark[exception-unbounded]` | 0.3909573892000083 | 0.00013798197253860585 | 99.96% | 283239.47% | 2833.39x | ✅ |
| `internal_task_done_callback_microbenchmark[finished-bounded]` | 0.0006645811923392462 | 0.0001357411607641795 | 79.57% | 389.59% | 4.90x | ✅ |
| `internal_task_done_callback_microbenchmark[finished-unbounded]` | 0.0006577406196807347 | 0.00013089689000971225 | 80.10% | 402.49% | 5.02x | ✅ |
