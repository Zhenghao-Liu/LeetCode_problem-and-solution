class ParkingSystem {
    int cnt[3];
public:
    ParkingSystem(int big, int medium, int small) {
        cnt[0]=big;
        cnt[1]=medium;
        cnt[2]=small;
    }
    
    bool addCar(int carType) {
        if (cnt[carType-1]==0)
            return false;
        --cnt[carType-1];
        return true;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
