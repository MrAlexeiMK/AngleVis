#include "pch.h"
#include "../AngleVisualizer/angle.h"
#include "../AngleVisualizer/angle.cpp"

TEST(TestAngle, TestAngleEquals) {
	EXPECT_EQ(angle(361), angle(1));
	EXPECT_EQ(angle(360), angle(0));
	EXPECT_EQ(angle(-180), angle(180));
	EXPECT_EQ(angle(-91), angle(269));
	EXPECT_EQ(angle(750), angle(30));
	EXPECT_EQ(angle(-750), angle(330));
	EXPECT_EQ(angle(31, 10), angle(30, 70));
	EXPECT_EQ(angle(31, 10), angle(29, 130));
	EXPECT_EQ(angle(0, 30), angle(1, -30));
	EXPECT_EQ(angle(-2, 10), angle(1, -170));
	EXPECT_EQ(angle(-2, 11, 5), angle(1, -170, 65));
	EXPECT_EQ(angle(1, 0, 0), angle(0, 0, 3600));
	EXPECT_EQ(angle(1, 1, 1), angle(0, 0, 3661));
}

TEST(TestAngle, TestAngleInput) {
	EXPECT_EQ(angle(30), angle("30d"));
	EXPECT_EQ(angle(365), angle("365d"));
	EXPECT_EQ(angle(1, 1, 1), angle("1d1m1s"));
	EXPECT_EQ(angle(0, 1, 1), angle("0d1m1s"));
	EXPECT_EQ(angle(0, 1, 1), angle("1m1s"));
	EXPECT_EQ(angle(-2, 0, 1), angle("-2d1s"));
	EXPECT_EQ(angle(-2, 0, 1), angle("-2d0m1s"));
	EXPECT_EQ(angle(0, 0, -3456), angle("-3456s"));
	EXPECT_EQ(angle(0, 0, -3456), angle("0d-3456s"));
	EXPECT_EQ(angle(0, 0, -3456), angle("0d0m-3456s"));
}

TEST(TestAngle, TestAngleSum) {
	EXPECT_EQ(angle(5) + angle(3), angle(8));
	EXPECT_EQ(angle(50) + angle(80), angle(130));
	EXPECT_EQ(angle(200) + angle(100), angle(130) + angle(170));
	EXPECT_EQ(angle(350) + angle(5), angle(355));
	EXPECT_EQ(angle(180) + angle(180), angle(0));
	EXPECT_EQ(angle(181) + angle(181), angle(2));
	EXPECT_EQ(angle(190) + angle(185), angle(15));
	EXPECT_EQ(angle(200) + angle(250), angle(90));
	EXPECT_EQ(angle(300) + angle(250), angle(190));
	EXPECT_EQ(angle(-900) + angle(500), angle(320));
	EXPECT_EQ(angle(1, 1, 1) + angle(2, 2, 2), angle(3, 3, 3));
	EXPECT_EQ(angle(1, 1, 1) + angle(-2, -2, -2), angle(-1, -1, -1));
}

TEST(TestAngle, TestAngleDiff) {
	EXPECT_EQ(angle(1, 1, 1) - angle(2, 2, 2), angle(-1, -1, -1));
	EXPECT_EQ(angle(365) - angle(360, 1, 1), angle(4, 58, 59));
	EXPECT_EQ(angle(-30) - angle(-40), angle(10));
}

TEST(TestAngle, TestAngleMultiply) {
	EXPECT_EQ(angle(30)*5, angle(150));
	EXPECT_EQ(angle(-30)*15, angle(270));
	EXPECT_EQ(angle(5, 5, 5) * 5, angle(25, 25, 25));
	EXPECT_EQ(angle(5, 5, 5) * (-5), angle(-25, -25, -25));
}

TEST(TestAngle, TestAngleDivision) {
	EXPECT_EQ(angle(30) / 5, angle(6));
	EXPECT_EQ(angle(360) / 360, angle(0));
	EXPECT_EQ(angle(1) / 10, angle(0));
	EXPECT_EQ(angle(25, 25, 25) / 10, angle(2, 2, 2));
}

TEST(TestAngle, TestAngleComparasions) {
	EXPECT_TRUE(angle("5d") > angle(4, 59, 59));
	EXPECT_TRUE(angle(355) > angle(4));
	EXPECT_TRUE(angle(-5) > angle(4));
	EXPECT_TRUE(angle(370, 10, 10) <= angle(11));
	EXPECT_TRUE(angle(360, 59, 60) == angle(1, 0, 0));
	EXPECT_TRUE(angle(360, 59, 60) != angle(1, 0, -10));
}

TEST(TestAngle, TestToRadians) {
	EXPECT_EQ(angle(90).toRadians(), M_PI / 2);
	EXPECT_EQ(angle(-90).toRadians(), 3 * M_PI / 2);
	EXPECT_EQ(angle(180).toRadians(), M_PI);
	EXPECT_EQ(angle(45).toRadians(), M_PI / 4);
}

TEST(TestAngle, TestToSeconds) {
	EXPECT_EQ(angle(1).toSeconds(), 3600);
	EXPECT_EQ(angle(50).toSeconds(), 50*3600);
	EXPECT_EQ(angle(0, 5).toSeconds(), 300);
	EXPECT_EQ(angle(-30).toSeconds(), 330*60*60);
	EXPECT_EQ(angle(0, -1).toSeconds(), 359*60*60 + 59*60);
}

TEST(TestAngle, TestToMinutes) {
	EXPECT_EQ(angle(1).toMinutes(), 60);
	EXPECT_EQ(angle(-1).toMinutes(), 359*60);
}