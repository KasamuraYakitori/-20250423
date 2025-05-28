#include "exam_japanese.h"
#include"utility.h"
#include<random>
using namespace std;

//漢字の読み取り問題を作成する
QuestionList CreteKanjiExam()
{
	static const struct {
		const char* kanji; //漢字
	    const char* reading; //読み
		const char* meaning; //意味
	}data[] = {
		{"市井", "しせい", "人が集まって暮らす所、町"},
		{"捺印", "なついん", "(署名と共に)印鑑を押すこと"},
		{"相殺", "そうさい", "足し引きの結果、差がなくなる事"},
		{"凡例", "はんれい", "本や図表の初めに使い方や約束事を箇条書きしたもの"},
		{"約定", "やくじょう", "約束して決めること、契約"},
	};

	constexpr int quizCount = 5;
	QuestionList questions;
	questions.reserve(quizCount);
	const vector<int> indices = CreateRandomIndices(size(data));
	random_device rd;

	//問題の種類を選ぶ
	int type = uniform_int_distribution<>(0, 1)(rd);
	if (type == 0) {
		//漢字の読みを答える問題
		for (int i = 0; i < quizCount; i++) {
			const auto& e = data[indices[i]];
			questions.push_back({
				"「" + string(e.kanji) + "」の読みをひらがなで答えよ",
				e.reading });
		}
	}
	return questions;
}