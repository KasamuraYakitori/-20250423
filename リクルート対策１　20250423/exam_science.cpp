#include"exam_science.h"
#include"utility.h"
#include<random>
using namespace std;


//�����̖����쐬����

QuestionList CreatePhysicsExam()
{
	QuestionList questions;
	questions.reserve(10);
	random_device rd;

	{
		//���������^��
		constexpr int divisors[] = { 1,2,3,4,5,6,10,13,15,20,30,60 };
		int i = uniform_int_distribution<>(0, size(divisors) - 1)(rd);
		int v = uniform_int_distribution<>(0, 10)(rd)*60 / divisors[i];
		int t = uniform_int_distribution<>(0, 10)(rd) * divisors[i];
		questions.push_back({
			"����" + to_string(v) + "km�ňړ�����Ԃ�����\n���̎Ԃ�" + to_string(v * t / 60) +
			"km�ړ�����̂ɂ����鎞�Ԃ𕪒P�ʂŋ��߂�",
			to_string(t) });

		int i = uniform_int_distribution<>(0, size(divisors) - 1)(rd);
		int v = uniform_int_distribution<>(0, 10)(rd) * 60 / divisors[i];
		int t = uniform_int_distribution<>(0, 10)(rd) * divisors[i];
		questions.push_back({
			"�����" + to_string(v) + "km�܂ŗ��ꂽ�n�_�܂ňړ�����̂�" + to_string(t) +
			"����������\n���̎Ԃ̕��ώ��������߂�",
			to_string(t) });

	}//���������ړ�
	{
		//�������x�����^��
		//����:v = v0 +at���g���ĉ������
		int v0 = uniform_int_distribution<>(	1,10)(rd);
		int a = uniform_int_distribution<>(1, 5)(rd);
		int t = uniform_int_distribution<>(1, 20)(rd);
		questions.push_back({
			"�b��" + to_string(v0) + "m�ňړ����Ă����Ԃ��i�s�����ɑ傫��" + to_string(a) +
			"m/s�œ��������x�����^�����n�߂�\n" + to_string(t) + "�b��̑��x��m/s�P�ʂŋ��߂�",
			to_string(v0 + a + t) });
		
	

	//����:x = v0t+1/2*at^2���g���ĉ������
		v0 = uniform_int_distribution<>(5, 20)(rd);//����
		a = uniform_int_distribution<>(1, 5)(rd)*2;//�����x
		t = uniform_int_distribution<>(1, 10)(rd);//�ړ�����
		questions.push_back({
			"�b��" + to_string(v0) + "m�ňړ����Ă��Ԃ��i�s�����ɑ傫��" + to_string(a) +
			"m/s�œ������x�����^�����n�߂��A\n�������n�߂Ă���" + to_string(t) +
			"�b��܂łɈړ�����������m�P�ʂŋ��߂�",
			to_string(v0 * t + a * t * t / 2) });

		//�����Fv^2-v0^2 = 2ax���g���ĉ������
		a = uniform_int_distribution<>(1,5)(rd)*2;//�����x
		t = uniform_int_distribution<>(1, 10)(rd);//�ړ�����
		v0 = -a * t;//����
		questions.push_back({
			"�b��" + to_string(v0) + "m�ňړ����Ă��Ԃ��u���[�L���������Ƃ���" + 
			to_string(v0*t+a*t*t/2) +"m�i��Œ�~����\n"+
			"�u���[�L�̉����x��m/s^2�P�ʂŋ��߂�",
			to_string(a)});
	}//���������x�����^��

	{//�d�͉����x
		int t = uniform_int_distribution<>(1, 10)(rd);//�ړ����x
		int x = 98 * t * t / 2;//10�{���邱�Ƃŏ����_�ȉ����ʂ܂ł𐮐��Ƃ��Ă���킷
		string answer = to_string(x / 10);//�������𕶎���
		if (x % 10) {
			//������������ꍇ�͏������𕶎���
			answer += '.';
			answer += '0' + x % 10;
		}
		questions.push_back({
			"�d�͉����x��9.8m/s^2�Ƃ���\n�\���ɍ����ʒu���畨�̂�Â��ɗ��Ƃ��ƕ��̂�" +
			to_string(t) + "�b�Ԃłw����������\n" +
			"�w�̒l�������_�ȉ����ʂ܂ŋ��߂�(��C��R�͂Ȃ����̂Ƃ���)",
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
			"�d�͉����x��9.8m/s^2�Ƃ���\n����" +
			to_string(v0) + "m/s�ŕ��̂������ɓ����グ�����A" +to_string(t)+
			"�b��̕��̂̑��x��Xm/s�ł���\n"+
			"X�̒l�������_�ȉ����ʂ܂ŋ��߂�(��C��R�͂Ȃ����̂Ƃ���)",
			answer });

	}//�d�͉����x

	{//����
		int s = uniform_int_distribution<>(5, 20)(rd); //��ʐ�
		int h = uniform_int_distribution<>(2, 10)(rd);//����
		int v = s * h + 5; //�̐ς����߁A�l�̌ܓ��̂���5��������
		string answer = to_string(v / 100);//���������𕶎���ɕϊ�
		v /= 10; //�����_�ȉ����ʈȉ��ɓ����镔�����̂Ă�
		if (v % 10)//�����_�ȉ����ʂ��O�ȊO�Ȃ�A�������𕶎���ɉ�����
		{
			answer += '.';
			answer += '0' + v % 10;
		}
		questions.push_back({
			"����100g�̕��̂ɓ����d�͂��PN�Ƃ���B\n��ʐ�" + to_string(s) + "cm^2,����" +
			to_string(h) + "cm�̉~�������S�ɐ����ɒ��߂�\n" +
			"���̎��A���̉~���ɓ������͂�X�j���[�g���ł���\n" +
			"X�̒l�������_���ʈȉ����l�̌ܓ����ċ��߂�",
			answer });

	}//����

	return questions;
};