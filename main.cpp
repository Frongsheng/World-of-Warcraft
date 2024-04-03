//#include<iostream>
//#include"headquarter.h"
//#include"city.h"
//#include<algorithm>
//using namespace std;
//
//int N;
//int initLifeValue[warriorNum];
//int attackValue[warriorNum];
//
//int doMoveForward(int time, Warrior* logred[], Warrior* logblue[])
//{
//	int isOver = 0, realOver = 0;
//	for (int i = 0; i <= N; i++)
//	{
//		if (logblue[i])
//		{
//			if (i >= 1 && !logred[i - 1])
//			{
//				logblue[i]->moveForward(time, isOver);
//				realOver = realOver | isOver;
//			}
//		}
//		if (logred[i])
//		{
//			if (i <= N && !logblue[i + 1])
//			{
//				logblue[i+1]->moveForward(time, isOver);
//				realOver = realOver | isOver;
//			}
//			logred[i]->moveForward(time, isOver);
//			realOver = realOver | isOver;
//		}
//
//	}
//	return realOver;
//}
//
//void doLionEscape(int time, Warrior* logred[], Warrior* logblue[],Headquarter& red,Headquarter& blue)
//{
//	for (int i = 0; i < N + 1; i++)
//	{
//		if (logred[i])
//		{
//			if (logred[i]->lionEscape(time))
//			{
//				red.eraseWarrior(logred[i]);
//				logred[i] = nullptr;
//			}
//		}
//		if (logblue[i])
//		{
//			if (logblue[i]->lionEscape(time))
//			{
//				blue.eraseWarrior(logblue[i]);
//				logblue[i] = nullptr;
//			}
//		}
//	}
//}
//
//void test01()
//{
//		int n, M, K, T;
//		cin >> n;
//		cin >> M >> N >> K >> T;
//		int Min = M + 1;
//		for (int j = 0; j < warriorNum; j++)
//		{
//			cin >> initLifeValue[j];
//			Min = min(Min, initLifeValue[j]);
//		}
//		for (int j = 0; j < warriorNum; j++)
//		{
//			cin >>attackValue[j];
//		}
//		cout << "Case " << n << " : " << endl;
//
//		vector<City>cities;
//		Headquarter red(r, M), blue(b, M);
//		Warrior* logred[22], * logblue[22];
//		for (int time = 0; T; time++, T -= 60)
//		{
//			red.makeWarriors(time, K);
//			blue.makeWarriors(time, K);
//
//			for (int j = 0; j <= N + 1; j++)
//			{
//				cities.push_back({ j,logred[j],logblue[j] });
//			}
//
//			if (T < 5) break;
//
//			for (int j = 0; j <= N + 1; j++)
//			{
//				logred[j]=logblue[j]=nullptr;
//			}
//			red.logExistence(logred);
//			blue.logExistence(logblue);
//
//			if (T < 5) break;
//
//			doLionEscape(time, logred, logblue, red, blue);
//			if (T < 10) break;
//
//			if (doMoveForward(time, logred, logblue) == 1)break;
//
//			for (int j = 0; j < N + 1; j++)
//			{
//				logred[j] = logblue[j] = nullptr;
//			}
//			red.logExistence(logred);
//			blue.logExistence(logblue);
//			cities.clear();
//
//			for (int j = 0; j < N + 1; j++)
//			{
//				cities.push_back({ j,logred[j],logblue[j] });
//			}
//			if (T < 35)break;
//
//			for (auto& c : cities)
//			{
//				c.doWolfSteal(time);
//			}
//			if (T < 40)break;
//
//			for (auto& c : cities)
//			{
//				c.doWar(time,red,blue);
//			}
//
//			red.tidyWarriors();
//			blue.tidyWarriors();
//			if (T < 50)break;
//
//			red.reportValue(time);
//			blue.reportValue(time);
//			if (T < 55)break;
//
//			for (auto& c : cities)
//			{
//				c.doReportWarrior(time);
//			}
//		}
//}
//
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}
//
#include <cstdio>
#include <string>
#include <vector>
#include <memory>
#include <unordered_map>

static
std::unordered_map<std::string, int> warriorStrength;

class Warrior {
protected:
	std::string name, camp;
	int id, strength, remMeta;

public:
	Warrior(
		const std::string& name_,
		const std::string& camp_,
		int id_, int strength_, int remMeta_
	) : name(name_), camp(camp_), id(id_),
		strength(strength_), remMeta(remMeta_) { }

	virtual
		void born(int timeStamp, int numsInCamp) {
		printf("%03d %s %s %d born with strength %d,"
			"%d %s in %s headquarter\n", timeStamp, camp.c_str(),
			name.c_str(), id, strength, numsInCamp, name.c_str(),
			camp.c_str());
	}

	virtual ~Warrior() {  }
};

const std::vector<std::string> WEAPON = {
	"sword", "bomb", "arrow"
};

class Dragon : public Warrior {
private:
	std::string weapon;
	double morale;

public:
	Dragon(
		const std::string& name_,
		const std::string& camp_,
		int id_, int strength_, int remMeta_
	) : Warrior(name_, camp_, id_, strength_, remMeta_),
		weapon(WEAPON[(id_ % 3)]),
		morale(1.0 * remMeta_ / strength_) { }

	void born(int timeStamp, int numsInCamp) {
		Warrior::born(timeStamp, numsInCamp);
		printf("It has a %s,and it's morale is %.2lf\n",
			weapon.c_str(), morale);
	}

	virtual ~Dragon() {  }
};

class Ninja : public Warrior {
private:
	std::string weapon1;
	std::string weapon2;

public:
	Ninja(
		const std::string& name_,
		const std::string& camp_,
		int id_, int strength_, int remMeta_
	) : Warrior(name_, camp_, id_, strength_, remMeta_),
		weapon1(WEAPON[(id_ % 3)]),
		weapon2(WEAPON[((id_ + 1) % 3)]) { }

	void born(int timeStamp, int numsInCamp) {
		Warrior::born(timeStamp, numsInCamp);
		printf("It has a %s and a %s\n",
			weapon1.c_str(), weapon2.c_str());
	}

	virtual ~Ninja() {  }
};

class Iceman : public Warrior {
private:
	std::string weapon;

public:
	Iceman(
		const std::string& name_,
		const std::string& camp_,
		int id_, int strength_, int remMeta_
	) : Warrior(name_, camp_, id_, strength_, remMeta_),
		weapon(WEAPON[(id_ % 3)]) { }

	void born(int timeStamp, int numsInCamp) {
		Warrior::born(timeStamp, numsInCamp);
		printf("It has a %s\n", weapon.c_str());
	}
};

class Lion : public Warrior {
private:
	int loyalty;

public:
	Lion(
		const std::string& name_,
		const std::string& camp_,
		int id_, int strength_, int remMeta_
	) : Warrior(name_, camp_, id_, strength_, remMeta_),
		loyalty(remMeta_) { }

	void born(int timeStamp, int numsInCamp) {
		Warrior::born(timeStamp, numsInCamp);
		printf("It's loyalty is %d\n", loyalty);
	}

	virtual ~Lion() {  }
};

using Wolf = Warrior;

std::shared_ptr<Warrior>
createWarrior(
	const std::string& warriorName,
	const std::string& headquarterName,
	int curID, int curStrength, int remMeta
) {
	if ("dragon" == warriorName) {
		return std::make_shared<Dragon>(
			warriorName, headquarterName, curID, curStrength, remMeta);
	}
	else if ("ninja" == warriorName) {
		return std::make_shared<Ninja>(
			warriorName, headquarterName, curID, curStrength, remMeta);
	}
	else if ("iceman" == warriorName) {
		return std::make_shared<Iceman>(
			warriorName, headquarterName, curID, curStrength, remMeta);
	}
	else if ("lion" == warriorName) {
		return std::make_shared<Lion>(
			warriorName, headquarterName, curID, curStrength, remMeta);
	}
	else if ("wolf" == warriorName) {
		return std::make_shared<Wolf>(
			warriorName, headquarterName, curID, curStrength, remMeta);
	}
	else {
		throw "Error: Nonexistent warroir name.";
	}
}

class Headquarter {
private:
	std::string name;
	std::vector<std::string> order;
	std::unordered_map<std::string, int> cntWarrior;
	int healthMeta, curID;
	size_t curIdx;

public:
	Headquarter(
		const std::string& name_,
		const std::vector<std::string>& order_,
		int healthMeta_, int curID_ = 1, size_t curIdx_ = 0
	) : name(name_), order(order_),
		healthMeta(healthMeta_), curID(curID_), curIdx(curIdx_) { }

	std::string getNextWarriorName() {
		size_t orderSize = order.size();
		for (size_t i = 0; i < orderSize; ++i) {
			std::string curName = order[curIdx];
			if (healthMeta >= warriorStrength[curName]) {
				return curName;
			}
			curIdx = (curIdx + 1) % orderSize;
		}
		return "NULL";
	}

	bool bornWarrior(int timeStamp) {
		std::string curName = getNextWarriorName();
		if ("NULL" == curName) {
			printf("%03d %s headquarter stops making warriors\n",
				timeStamp, name.c_str());
			return false;
		}
		int curStrength = warriorStrength[curName];
		healthMeta -= curStrength;
		int curNumsInCamp = ++cntWarrior[curName];
		try {
			createWarrior(
				curName, name, curID, curStrength, healthMeta
			)->born(timeStamp, curNumsInCamp);
		}
		catch (const char* errorMsg) {
			printf("%s\n", errorMsg);
			return false;
		}
		curID++;
		curIdx = (curIdx + 1) % order.size();
		return true;
	}
};

int main() {
	int caseNums;
	scanf("%d", &caseNums);
	for (int cs = 1; cs <= caseNums; ++cs) {
		int meta, dragon, ninja, iceman, lion, wolf;
		scanf("%d%d%d%d%d%d", &meta, &dragon, &ninja,
			&iceman, &lion, &wolf);
		warriorStrength = {
			{"dragon", dragon}, {"ninja", ninja}, {"iceman", iceman},
			{"lion", lion}, {"wolf", wolf}
		};
		Headquarter red(
			"red", { "iceman", "lion", "wolf", "ninja", "dragon" }, meta);
		Headquarter blue(
			"blue", { "lion", "dragon", "ninja", "iceman","wolf" }, meta);
		printf("Case:%d\n", cs);
		bool redOK = true, blueOK = true;
		for (int curTime = 0; ; ++curTime) {
			if (redOK) {
				redOK = red.bornWarrior(curTime);
			}
			if (blueOK) {
				blueOK = blue.bornWarrior(curTime);
			}
			if (!redOK && !blueOK) {
				break;
			}
		}
	}
	return 0;
}
