type ParkingSystem struct {
	cnt [4]int
}

func Constructor(big int, medium int, small int) ParkingSystem {
	var ans ParkingSystem
	ans.cnt[1] = big
	ans.cnt[2] = medium
	ans.cnt[3] = small
    return ans
}

func (this *ParkingSystem) AddCar(carType int) bool {
	if this.cnt[carType] > 0 {
		this.cnt[carType]--
		return true
	}
	return false
}

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * obj := Constructor(big, medium, small);
 * param_1 := obj.AddCar(carType);
 */
