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

		 i = uniform_int_distribution<>(0, size(divisors) - 1)(rd);
		 v = uniform_int_distribution<>(0, 10)(rd) * 60 / divisors[i];
		 t = uniform_int_distribution<>(0, 10)(rd) * divisors[i];
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
			"m/sで等速加速度直線運動を始めた\n" + to_string(t) + "秒後の速度をm/s単位で求めよ",
			to_string(v0 + a + t) });
		
	

	//公式:x = v0t+1/2*at^2を使って解く問題
		v0 = uniform_int_distribution<>(5, 20)(rd);//初速
		a = uniform_int_distribution<>(1, 5)(rd)*2;//加速度
		t = uniform_int_distribution<>(1, 10)(rd);//移動時間
		questions.push_back({
			"秒速" + to_string(v0) + "mで移動してた車が進行方向に大きさ" + to_string(a) +
			"m/sで等加速度直線運動を始めた、\n加速を始めてから" + to_string(t) +
			"秒後までに移動した距離をm単位で求めよ",
			to_string(v0 * t + a * t * t / 2) });

		//公式：v^2-v0^2 = 2axを使って解く問題
		a = uniform_int_distribution<>(1,5)(rd)*2;//加速度
		t = uniform_int_distribution<>(1, 10)(rd);//移動時間
		v0 = -a * t;//初速
		questions.push_back({
			"秒速" + to_string(v0) + "mで移動してた車がブレーキをかけたところ" + 
			to_string(v0*t+a*t*t/2) +"m進んで停止した\n"+
			"ブレーキの加速度をm/s^2単位で求めよ",
			to_string(a)});
	}//等速加速度直線運動

	{//重力加速度
		int t = uniform_int_distribution<>(1, 10)(rd);//移動速度
		int x = 98 * t * t / 2;//10倍することで小数点以下第一位までを整数としてあらわす
		string answer = to_string(x / 10);//整数部を文字列化
		if (x % 10) {
			//少数部がある場合は少数部を文字列化
			answer += '.';
			answer += '0' + x % 10;
		}
		questions.push_back({
			"重力加速度を9.8m/s^2とする\n十分に高い位置から物体を静かに落とすと物体は" +
			to_string(t) + "秒間でＸｍ落下する\n" +
			"Ｘの値を少数点以下第一位まで求めよ(空気抵抗はないものとする)",
			answer });

		int v0 = uniform_int_distribution<>(1, 10)(rd);
		t = uniform_int_distribution<>(1, 10)(rd);
		int v = v0 * 10 - 98 * t;
		answer.clear();
		if (v < 0) {
			v = -v;
			answer = '-';
		}
		answer += to_string(v / 10);
		if (v % 10) {
			answer += '.';
			answer += '0' + v % 10;
		}
		questions.push_back({
			"重力加速度を9.8m/s^2とする\n初速" +
			to_string(v0) + "m/sで物体を鉛直に投げ上げた時、" +to_string(t)+
			"秒後の物体の速度はXm/sである\n"+
			"Xの値を小数点以下第一位まで求めよ(空気抵抗はないものとする)",
			answer });

	}//重力加速度

	{//浮力
		int s = uniform_int_distribution<>(5, 20)(rd); //底面積
		int h = uniform_int_distribution<>(2, 10)(rd);//高さ
		int v = s * h + 5; //体積を求め、四捨五入のため5を加える
		string answer = to_string(v / 100);//整数部分を文字列に変換
		v /= 10; //小数点以下第二位以下に当たる部分を捨てる
		if (v % 10)//小数点以下第一位が０以外なら、少数部を文字列に加える
		{
			answer += '.';
			answer += '0' + v % 10;
		}
		questions.push_back({
			"質量100gの物体に働く重力を１Nとする。\n底面積" + to_string(s) + "cm^2,高さ" +
			to_string(h) + "cmの円柱を完全に水中に沈めた\n" +
			"この時、この円柱に働く浮力はXニュートンである\n" +
			"Xの値を小数点第二位以下を四捨五入して求めよ",
			answer });

		int x = uniform_int_distribution<>(20, 50)(rd) * 10;//重さ(水中)
		int y = uniform_int_distribution<>(x / 2, x - 1)(rd) * 10;//重さ(水中)
		int z = x - y + 5;
		answer = to_string(z / 100);
		z /= 10;
		if (z % 10)
		{
			answer += '.';
			answer += '0' + z % 10;
		}

		questions.push_back({
			"質量100gの物体に働く重力を１Nとする。\nある物体の重さをばねはかりで測ると" + to_string(x) + "ｇを示した\n" +
			to_string(h) + "gを示した\n" +"この物体を完全に水に入れたところ、ばねばかりは"+
			to_string(y) +"gを示した\nこの時物体に働く浮力はＸニュートンである\n"+
			"Xの値を小数点第二位以下を四捨五入して求めよ",
			answer });

		int p0 = uniform_int_distribution<>(1, 9)(rd) * 100;//密度
		s = uniform_int_distribution<>(5,10)(rd);//底面積
		h = uniform_int_distribution<>(5, 10)(rd);//高さ
		z = h * p0 + 50;
		answer = to_string(z / 1000);
		z /= 100;
		if (z % 10)
		{
			answer += '.';
			answer += '0' + z % 10;
		}

		questions.push_back({
			"密度" + to_string(p0) + "kg/m^,底面積" +to_string(s)+"cm^2,高さ"+
			to_string(h) + "cmの物体を水に沈めようとしたところ、Xcm沈んで静止した\n" +
			"Xの値を小数点第１位以下を四捨五入して求めよ",
			answer });
	}//浮力

	{//ばね
		int a = uniform_int_distribution<>(10, 30)(rd) * 100;//自然長
		int x = uniform_int_distribution<>(1, a / 2)(rd);//自然長からの変化量
		int m = uniform_int_distribution<>(1, 20)(rd) * 10;//質量
		int k = 100 * m / x + 5;//ｋの100倍を求め、四捨五入のため5を足す
		string answer = to_string(k / 100);//整数部を文字列に加える
		k /= 10;
		if (k % 10)
		{
			answer += '.';
			answer += '0' + k % 10;
		}

		questions.push_back({
			"重力加速度を10m/s^2とする\n長さ" + to_string(a) + "cmのばねの先端に"+
			to_string(a+ x) + "cmになった" +
			"このばねの「ばね定数」を小数点第２位以下を四捨五入して求めよ",
			answer });

		int k1 = uniform_int_distribution<>(1, 3)(rd);//ばね定数１(N/m)
		int k2 = uniform_int_distribution<>(1, 9)(rd);//ばね定数２(N/m)
		if (k2 >= k1) {
			k2++;
		}
		m = uniform_int_distribution<>(1, 10)(rd) * 10;//質量
		x = 100 * m * (k1 + k2) / (k1 * k2) + 5;
		answer = to_string(x / 100);
		x /= 10;
		if (x % 10)
		{
			answer += '.';
			answer += '0' + k % 10;
		}

		questions.push_back({
			"重力加速度を10m/s^2とする\nばね定数が" + to_string(k1) + "と" +to_string(k2)+
			"の二つのばねを直列につなぎ、" + to_string(m)+"gのおもりを付けて天井から吊り下げた\n" +
			"するとばねの長さが合わせてXcm伸びて静止した^n"+
			"Xの値を小数点以下第二位を四捨五入して求めよ",
			answer });

		 k1 = uniform_int_distribution<>(1, 10)(rd);//自然長
		 k2 = uniform_int_distribution<>(1, 10)(rd);//自然長からの変化量
		 m = uniform_int_distribution<>(1, 10)(rd) * 10;//質量
		 x = 100 * m / (k1 + k2) + 5;
		 answer = to_string(x / 100);
		 x /= 10;
		 if (x % 10)
		 {
			 answer += '.';
			 answer += '0' + k % 10;
		 }

		 questions.push_back({
			 "重力加速度を10m/s^2とする\nばね定数が" + to_string(k1) + "と" + to_string(k2) +
			 "の二本のばねを水平な天井に固定し、ばねの下端に木の棒に水平に取り付けた\n" +
			 "この棒の中央に質量" +to_string(m)+"gのおもりを吊り下げた\n"+
			 "するとばねの長さがそれぞれXmだけ伸びて静止した\n"
			 "Xの値を小数点以下第二位を四捨五入して求めよ",
			 answer });
	}//ばね

	{//振り子
		int l = uniform_int_distribution<>(1, 10)(rd);//長さ
		int m = uniform_int_distribution<>(1, 10)(rd);//質量

		questions.push_back({
			 "長さ" + to_string(l*l) + "mの糸に質量" + to_string(m) +
			 "kgのおもりを付け、わずかに揺らしたところ、周期はX秒だった。Xの値を求めよ" +
			 "なお重力加速度gと円周率πについて、π＝√gが成り立つものとする" ,
			
			 to_string(2*1)});

		 l = uniform_int_distribution<>(1, 10)(rd);//長さ
		 m = uniform_int_distribution<>(1, 10)(rd);//質量
		 int max_v = (int)sqrt(20 * 1);//速度の上限(2gh=v^2を根拠とする)
		 int v = uniform_int_distribution<>(1, max_v)(rd);//速度
		 questions.push_back({
			  "重力加速度を10m/s^2とする\n長さ" + to_string(l) + "mの糸に質量" + to_string(m) +
			  "kgの重りを付けた振り子がある\nこの重りを最下点から高さ" +
			 to_string(v * v * 100 / 20) + "cmの位置で静かに離した\n" +
			  "このとき、重りが最下点を通過するときの速度をm/s単位で求めよ" ,
			  to_string(v) });
	}//振り子
	return questions;
};