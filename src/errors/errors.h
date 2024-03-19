
/**
 * approximateError: calculates the percentaege of approximate error
 * @previous: previous value
 * @current: current value
 * Return: percentage of approximation error
 */
inline double approximateError(const double& previous, const double& current)
{
    return current > previous ? (current - previous) / current * 100 : (previous - current) / current * 100;
}