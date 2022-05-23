#ifndef employee_h
#define employee_h


class employee {
private:
	const int id;
	char name[20];
	int salaryperhour, monthlyworkedhours, taxpaid;
	int yearofjoining;
	int monthlysalary;

public:
	employee(int id);
	void updatehours();
	void changesalary();
	void cal_monthly_sal();
	void taxdeduction();
	void healthinsurnce();
	void senioremployee();
	void generatereceipt();

};

#endif;