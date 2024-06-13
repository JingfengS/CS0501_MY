//
// Created by Jingfeng Sun on 2024/6/13.
//
#include "gtest/gtest.h"
#include <ClassAranger.h>

class ClassArangerTester : public ::testing::Test {
protected:
    ClassAranger ca;

    void SetUp() override {
        ca.addClass(1, "高数");
        ca.addClass(2, "大物I");
        ca.addClass(3, "大物II");
        ca.addClass(4, "离散数学");
        ca.addClass(5, "程序设计");
        ca.addClass(6, "数据结构");
        ca.addClass(7, "编译原理");
        ca.addClass(8, "数据库");
        ca.addClass(9, "软件工程");
		ca.addPrerequisite("高数", "大物I");
		ca.addPrerequisite("大物I", "大物II");
		ca.addPrerequisite("高数", "离散数学");
		ca.addPrerequisite("高数", "程序设计");
		ca.addPrerequisite("离散数学", "数据结构");
		ca.addPrerequisite("离散数学", "编译原理");
		ca.addPrerequisite("程序设计", "数据结构");
		ca.addPrerequisite("程序设计", "数据库");
		ca.addPrerequisite("程序设计", "软件工程");
		ca.addPrerequisite("数据结构", "编译原理");
		ca.addPrerequisite("数据结构", "数据库");
		ca.addPrerequisite("数据库", "软件工程");
    };
};

TEST_F(ClassArangerTester, ArrangeClasses) {
    std::vector<std::string> classes = ca.arrangeClasses();
    ASSERT_EQ(classes.size(), 9);
    std::cout << "The order of classes is: ";
    for (const auto& className : classes) {
        std::cout << className << " ";
    }
}
