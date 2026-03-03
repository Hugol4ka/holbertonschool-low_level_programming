## Green Efficiency Analysis

## Measurement Methodology
To ensure the scientific validity of this analysis, the performance of two distinct algorithms—referred to as "Naive" and "Single-pass"—was evaluated under controlled conditions. The testing environment executed each algorithm three times to account for background system noise and hardware fluctuations. The primary metric recorded was execution time in seconds, using a fixed workload of 100,000,000 iterations. By calculating the arithmetic mean of these three runs, we established a reliable baseline for comparison, minimizing the impact of outliers such as a temporary CPU spike or memory latency during any single run.

## Observed Performance Differences
The data collected reveals a massive disparity in efficiency between the two approaches. The Naive algorithm showed a consistent execution time, with an average of approximately 2.248632 seconds (based on individual runs of 2.238s, 2.246s, and 2.260s). In stark contrast, the Single-pass algorithm demonstrated near-instantaneous results, with an average execution time of only 0.000086 seconds.

When calculating the relative difference, we find that the Naive algorithm is approximately 26,146 times slower than its counterpart. While the Naive algorithm provides the correct result (625,025,000), its structural inefficiency becomes evident when compared to the Single-pass method, which achieves its result (25,000) with significantly fewer computational cycles.

## Relation Between Runtime and Energy Consumption
In computer engineering, execution time is a direct proxy for energy consumption. A CPU consumes power primarily through the switching of transistors; therefore, an algorithm that runs for 2.24 seconds keeps the processor in a high-power state for much longer than one that runs for less than a millisecond.

Because the Naive algorithm requires 26,146 times more time to complete the same number of iterations, it effectively consumes vastly more Watt-hours. In a "Green IT" context, using the Single-pass algorithm isn't just a matter of speed; it is a critical optimization that reduces the carbon footprint of the software. Scaling this inefficiency to a data center level would result in massive, unnecessary electricity waste.

## Limitations of the Experiment
While the results are conclusive, a few limitations must be noted:

1/ Hardware Specificity: The measurements were taken on a specific CPU architecture. Results might vary on different hardware or virtualized environments.

2/ Workload Scope: The experiment focused on a high iteration count (100M). The difference might be less noticeable on very small datasets where overhead costs dominate.

3/ Environment Noise: Although three runs were averaged, background processes on the operating system can still introduce minor variability in micro-second measurements.

## Practical Engineering Takeaway
The core takeaway for a software engineer is that algorithmic complexity (O-notation) outweighs hardware power. No amount of CPU overclocking can compensate for an inefficient algorithm. When designing systems, prioritizing a single-pass logic over nested or repetitive iterations is the most effective way to ensure both high performance and environmental sustainability. Efficiency in code is the first step toward "Green Software Engineering."