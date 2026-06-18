class Solution {
public:
    double angleClock(int hour, int minutes) {
        double h_angle = 30.0*hour + 0.5*minutes;
        double m_angle = 6.0 * minutes;
        double diff = abs(h_angle-m_angle);
        return min(diff,360.0-diff);

    }
};