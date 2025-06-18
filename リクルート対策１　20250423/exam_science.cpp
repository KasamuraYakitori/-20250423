#include"exam_science.h"
#include"utility.h"
#include<random>
using namespace std;


//物理の問題を作成する

QuestionList CreatePhysicsExam()
{
	QuestionList questions;
	questions.reserve(10);
	random_device rd;

	{
		//等速直線運動
		constexpr int divisors[] = { 1,2,3,4,5,6,10,13,15,20,30,60 };
		int i = uniform_int_distribution<>(0, size(divisors) - 1)(rd);
		int v = uniform_int_distribution<>(0, 10)(rd)*60 / divisors[i];
		int t = uniform_int_distribution<>(0, 10)(rd) * divisors[i];
		questions.push_back({
			"時速" + to_string(v) + "kmで移動する車がある\nこの車が" + to_string(v * t / 60) +
			"km移動するのにかかる時間を分単位で求めよ",
			to_string(t) });

		int i = uniform_int_distribution<>(0, size(divisors) - 1)(rd);
		int v = uniform_int_distribution<>(0, 10)(rd) * 60 / divisors[i];
		int t = uniform_int_distribution<>(0, 10)(rd) * divisors[i];
		questions.push_back({
			"ある車" + to_string(v) + "kmまで離れた地点まで移動するのに" + to_string(t) +
			"分かかった\nこの車の平均時速を求めよ",
			to_string(t) });

	}//等速直線移動
	{
		//等速速度直線運動
		//公式:v = v0 +atを使って解く問題
		int v0 = uniform_int_distribution<>(	1,10)(rd);
		int a = uniform_int_distribution<>(1, 5)(rd);
		int t = uniform_int_distribution<>(1, 20)(rd);
		questions.push_back({
			"秒速" + to_string(v0) + "mで移動していた車が進行方向に大きさ" + to_string(a) +
			"m/sで等速加速度直線運動を始めた\n" + to_string(t) + "病後の速度をm/s単位で求めよ",
			to_string(v0 + a + t) });
		//等速加速度直線運動
	}
	return questions;
};