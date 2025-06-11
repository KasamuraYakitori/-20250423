#include"exam_English.h"
#include"utility.h"
#include<random>
using namespace std;

//英単語の問題を作成する
QuestionList CreateEnglishWordExam()
{
	 const struct {
		const char* word; //読み
		const char* reading; //読み
		const char* meaning; //意味
	 }data[] = {
		 {"state", "ステート", "状態"},
		 {"business", "ビジネス", "仕事"},
		 {"abstract", "アブストラクト", "抽象的な"},
		 {"concract", "コンクリート", "具体的な"},
		 {"digital", "デジタル", "数字で情報を伝える"},
		 {"analogue", "アナログ", "類似しているもの、類似物"},
		 {"exchange", "エクスチェンジ", "交換、両替、為替"},
		 {"infrastructure", "インフラストラクチャ", "下部構造、基礎となる施設や設備"},
		 {"knowledge", "ナレッジ", "知識"},
		 {"credit", "クレジット", "信用"},
	 };

	 constexpr int quizCount = 5;
	 QuestionList questions;
	 questions.reserve(quizCount);
	 const vector<int> indices = CreateRandomIndices(size(data));
	 random_device rd;


	 //問題の種類をランダムに選ぶ
	 const int type = uniform_int_distribution<>(0, 3)(rd);
	 switch (type) {
	 case 0://意味から英単語を答える
		 for (int i = 0; i < quizCount; i++) {
			 const auto& e = data[indices[i]];
			 questions.push_back({
				 "「" + string(e.meaning) + "」を意味する英単語を答えよ",
				 e.word });
		 }
		 break;
	 case 1: //読みから英単語を答える
		 for (int i = 0; i < quizCount; i++) {
			 const auto& e = data[indices[i]];
			 questions.push_back({
				 "カタカナの読み「" + string(e.meaning) + "」を対応する英単語を答えよ",
				 e.word });
		 }

		 break;
	 case 2: //英単語から読みを答える
		 for (int i = 0; i < quizCount; i++) {
			 const auto& e = data[indices[i]];
			 questions.push_back({
		string(e.meaning) + "の読み方をカタカナで答えよ",
				 e.word });
		 }

		 break;
	 case 3: //英単語の意味を答える
		 for (int i = 0; i < quizCount; i++) {
			 //間違った番号をランダムに選ぶ
			 const int correctIndex = indices[i];
			 vector<int> answers = CreateWrongIndices(size(data), correctIndex);

			 //ランダムな位置を正しい番号で上書き
			 const int correctNo = uniform_int_distribution<>(1, 3)(rd);
			 answers[correctNo - 1] = correctIndex;

			 //問題文を作成
			 string s = "「" + string(data[correctIndex].word) +
				 "」の意味として正しい番号を選べ\n";
			 s += std::string(" 1:") + data[answers[0]].meaning + "\n";
			 s += std::string(" 2:") + data[answers[1]].meaning + "\n";
			 s += std::string(" 3:") + data[answers[2]].meaning + "\n";

			 questions.push_back({ s, to_string(correctNo) });
		 }
		 break;
	 }//swithe(type)
	 return questions;
}