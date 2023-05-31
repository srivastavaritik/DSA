class UndergroundSystem {
private:
    struct CheckInData {
        string stationName;
        int time;
    };

    unordered_map<int, CheckInData> checkIns;
    unordered_map<string, unordered_map<string, pair<double, int>>> travelTimes;

public:
    UndergroundSystem() {}

    void checkIn(int id, string stationName, int t) {
        checkIns[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t) {
        CheckInData checkInData = checkIns[id];
        checkIns.erase(id);

        string startStation = checkInData.stationName;
        double travelTime = t - checkInData.time;

        auto& stationTimes = travelTimes[startStation][stationName];
        stationTimes.first += travelTime;
        stationTimes.second++;
    }

    double getAverageTime(string startStation, string endStation) {
        const auto& stationTimes = travelTimes[startStation][endStation];
        return stationTimes.first / stationTimes.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */