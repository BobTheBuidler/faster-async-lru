#### [unknown](https://github.com/BobTheBuidler/faster-async-lru/blob/compile/unknown) - [view benchmarks](https://github.com/BobTheBuidler/faster-async-lru/blob/compile/unknown)

| Function | Reference Mean | Faster Mean | % Change | Speedup (%) | x Faster | Faster |
|----------|---------------|-------------|----------|-------------|----------|--------|
| `cache_clear_benchmark[bounded]` | 8.881438857858736e-07 | 4.995300613009768e-07 | 43.76% | 77.80% | 1.78x | ✅ |
| `cache_clear_benchmark[meth-bounded]` | 1.1685265551170746e-06 | 5.027983884849393e-07 | 56.97% | 132.40% | 2.32x | ✅ |
| `cache_clear_benchmark[meth-unbounded]` | 1.1275954940641585e-06 | 4.995042666375108e-07 | 55.70% | 125.74% | 2.26x | ✅ |
| `cache_clear_benchmark[unbounded]` | 8.848280209944275e-07 | 4.947539314747012e-07 | 44.08% | 78.84% | 1.79x | ✅ |
| `cache_fill_eviction_benchmark` | 0.09668595099999132 | 0.0914232642727303 | 5.44% | 5.76% | 1.06x | ✅ |
| `cache_hit_benchmark[bounded]` | 0.0010437814112256884 | 0.0005330919083192787 | 48.93% | 95.80% | 1.96x | ✅ |
| `cache_hit_benchmark[meth-bounded]` | 0.002092163229613443 | 0.001899665312138959 | 9.20% | 10.13% | 1.10x | ✅ |
| `cache_hit_benchmark[meth-unbounded]` | 0.002107379685225136 | 0.0018355587257140845 | 12.90% | 14.81% | 1.15x | ✅ |
| `cache_hit_benchmark[unbounded]` | 0.0010520655555557703 | 0.0005350417858809564 | 49.14% | 96.63% | 1.97x | ✅ |
| `cache_info_benchmark[bounded]` | 0.0004981868495750673 | 0.00038843592821148035 | 22.03% | 28.25% | 1.28x | ✅ |
| `cache_info_benchmark[meth-bounded]` | 0.0005716835171193307 | 0.00039790977662226905 | 30.40% | 43.67% | 1.44x | ✅ |
| `cache_info_benchmark[meth-unbounded]` | 0.0005694961517755801 | 0.0004086580580286469 | 28.24% | 39.36% | 1.39x | ✅ |
| `cache_info_benchmark[unbounded]` | 0.0005051871897488186 | 0.00039497700281569204 | 21.82% | 27.90% | 1.28x | ✅ |
| `cache_invalidate_benchmark[bounded]` | 7.656151744050544e-05 | 2.6123484545783516e-05 | 65.88% | 193.08% | 2.93x | ✅ |
| `cache_invalidate_benchmark[meth-bounded]` | 0.0002587472700460266 | 0.00020861231896546082 | 19.38% | 24.03% | 1.24x | ✅ |
| `cache_invalidate_benchmark[meth-unbounded]` | 0.00025103700923647575 | 0.00020762938839062977 | 17.29% | 20.91% | 1.21x | ✅ |
| `cache_invalidate_benchmark[unbounded]` | 7.415060934130997e-05 | 2.633140185060466e-05 | 64.49% | 181.61% | 2.82x | ✅ |
| `cache_miss_benchmark[bounded]` | 0.00022533577183106015 | 0.0001878535519288812 | 16.63% | 19.95% | 1.20x | ✅ |
| `cache_miss_benchmark[meth-bounded]` | 0.0002849435076455988 | 0.0002548668858860491 | 10.56% | 11.80% | 1.12x | ✅ |
| `cache_miss_benchmark[meth-unbounded]` | 0.00028345461959674483 | 0.0002541264367816544 | 10.35% | 11.54% | 1.12x | ✅ |
| `cache_miss_benchmark[unbounded]` | 0.00022720257551060635 | 0.00018868532294656976 | 16.95% | 20.41% | 1.20x | ✅ |
| `cache_ttl_expiry_benchmark[bounded]` | 1.8879207142965012e-05 | 1.834540565908691e-05 | 2.83% | 2.91% | 1.03x | ✅ |
| `cache_ttl_expiry_benchmark[meth-bounded]` | 2.1369956422655966e-05 | 2.0386259249290015e-05 | 4.60% | 4.83% | 1.05x | ✅ |
| `cache_ttl_expiry_benchmark[meth-unbounded]` | 2.2365187798892733e-05 | 2.0402344726435313e-05 | 8.78% | 9.62% | 1.10x | ✅ |
| `cache_ttl_expiry_benchmark[unbounded]` | 1.9133222451422562e-05 | 1.7717313079049353e-05 | 7.40% | 7.99% | 1.08x | ✅ |
| `concurrent_cache_hit_benchmark[bounded]` | 0.0005552469460744626 | 0.0005060329274403594 | 8.86% | 9.73% | 1.10x | ✅ |
| `concurrent_cache_hit_benchmark[meth-bounded]` | 0.0006713716292525419 | 0.0006552925717889916 | 2.39% | 2.45% | 1.02x | ✅ |
| `concurrent_cache_hit_benchmark[meth-unbounded]` | 0.0006768168461550116 | 0.0006528114955893909 | 3.55% | 3.68% | 1.04x | ✅ |
| `concurrent_cache_hit_benchmark[unbounded]` | 0.0005565385063482889 | 0.0005198241091645448 | 6.60% | 7.06% | 1.07x | ✅ |
| `internal_cache_hit_microbenchmark[bounded]` | 2.7896318712791647e-05 | 9.394251740412572e-06 | 66.32% | 196.95% | 2.97x | ✅ |
| `internal_cache_hit_microbenchmark[unbounded]` | 2.7735799788298358e-05 | 9.427050388644932e-06 | 66.01% | 194.22% | 2.94x | ✅ |
| `internal_cache_miss_microbenchmark[bounded]` | 1.818674834109012e-05 | 3.5193429229760814e-06 | 80.65% | 416.77% | 5.17x | ✅ |
| `internal_cache_miss_microbenchmark[unbounded]` | 1.837864250847554e-05 | 3.638009973044358e-06 | 80.21% | 405.18% | 5.05x | ✅ |
| `internal_task_done_callback_microbenchmark[cancelled-bounded]` | 0.0005317051165048685 | 0.000476566399999657 | 10.37% | 11.57% | 1.12x | ✅ |
| `internal_task_done_callback_microbenchmark[cancelled-unbounded]` | 0.0005280761840741526 | 0.00047026005739435534 | 10.95% | 12.29% | 1.12x | ✅ |
| `internal_task_done_callback_microbenchmark[exception-bounded]` | 0.2051541258000043 | 0.1999482327999999 | 2.54% | 2.60% | 1.03x | ✅ |
| `internal_task_done_callback_microbenchmark[exception-unbounded]` | 0.20485588960000883 | 0.19999786280000648 | 2.37% | 2.43% | 1.02x | ✅ |
| `internal_task_done_callback_microbenchmark[finished-bounded]` | 0.0006428591911264359 | 0.0005500418433229642 | 14.44% | 16.87% | 1.17x | ✅ |
| `internal_task_done_callback_microbenchmark[finished-unbounded]` | 0.0006432382694409618 | 0.0005254727225434781 | 18.31% | 22.41% | 1.22x | ✅ |
