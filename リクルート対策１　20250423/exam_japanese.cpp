#include "exam_japanese.h"
#include"utility.h"
#include<random>
using namespace std;

//�����̓ǂݎ������쐬����
QuestionList CreteKanjiExam()
{
	static const struct {
		const char* kanji; //����
	    const char* reading; //�ǂ�
		const char* meaning; //�Ӗ�
	}data[] = {
		{"�s��", "������", "�l���W�܂��ĕ�炷���A��"},
		{"���", "�Ȃ���", "(�����Ƌ���)��ӂ���������"},
		{"���E", "��������", "���������̌��ʁA�����Ȃ��Ȃ鎖"},
		{"�}��", "�͂�ꂢ", "�{��}�\�̏��߂Ɏg������񑩎����ӏ�������������"},
		{"���", "�₭���傤", "�񑩂��Č��߂邱�ƁA�_��"},
	};

	constexpr int quizCount = 5;
	QuestionList questions;
	questions.reserve(quizCount);
	const vector<int> indices = CreateRandomIndices(size(data));
	random_device rd;

	//���̎�ނ�I��
	int type = uniform_int_distribution<>(0, 1)(rd);
	if (type == 0) {
		//�����̓ǂ݂𓚂�����
		for (int i = 0; i < quizCount; i++) {
			const auto& e = data[indices[i]];
			questions.push_back({
				"�u" + string(e.kanji) + "�v�̓ǂ݂��Ђ炪�Ȃœ�����",
				e.reading });
		}
	}
	return questions;
}