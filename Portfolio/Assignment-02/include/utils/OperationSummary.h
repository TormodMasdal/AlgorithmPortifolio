#pragma once

/**
 * @brief Small helper struct used to track how a sort or search performed.
 * @details Collects some basic stats to show in the test output.
 */
struct OperationSummary {
    long long comparisons = 0;
    long long swaps = 0;
    double timeSpentMs = 0.0;
};
