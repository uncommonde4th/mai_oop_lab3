#include <gtest/gtest.h>
#include "../include/point.h"
#include "../include/trapezoid.h"
#include "../include/rhombus.h"
#include "../include/pentagon.h"
#include "../include/array.h"
#include <sstream>

TEST(TrapezoidTest, AreaCalculation) {
    Trapezoid trap;
    std::stringstream input("0 0 4 0 3 3 1 3");
    input >> trap;
    
    EXPECT_NEAR(trap.getArea(), 9.0, 1e-6);
}

TEST(TrapezoidTest, CenterTest) {
    Trapezoid trap;
    std::stringstream input("0 0 4 0 3 3 1 3");
    input >> trap;
    
    Point center = trap.getCenter();
    EXPECT_NEAR(center.x, 2.0, 1e-6);
    EXPECT_NEAR(center.y, 1.5, 1e-6);
}

TEST(RhombusTest, AreaCalculation) {
    Rhombus rhombus;
    std::stringstream input("0 0 2 3 4 0 2 -3");
    input >> rhombus;
    
    EXPECT_NEAR(rhombus.getArea(), 12.0, 1e-6);
}

TEST(RhombusTest, CenterTest) {
    Rhombus rhombus;
    std::stringstream input("0 0 2 3 4 0 2 -3");
    input >> rhombus;
    
    Point center = rhombus.getCenter();
    EXPECT_NEAR(center.x, 2.0, 1e-6);
    EXPECT_NEAR(center.y, 0.0, 1e-6);
}

TEST(PentagonTest, AreaCalculation) {
    Pentagon pentagon;
    std::stringstream input("0 0 2 0 3 1 1 2 -1 1");
    input >> pentagon;
    EXPECT_NEAR(pentagon.getArea(), 5.0, 1e-6);
}

TEST(PentagonTest, CenterTest) {
    Pentagon pentagon;
    std::stringstream input("0 0 2 0 3 1 1 2 -1 1");
    input >> pentagon;
    
    Point center = pentagon.getCenter();
    EXPECT_NEAR(center.x, 1.0, 1e-6);
    EXPECT_NEAR(center.y, 0.8, 1e-6);
}

TEST(ArrayTest, AddTrapezoid) {
    Array array(5);
    
    Trapezoid* trap = new Trapezoid();
    std::stringstream input("0 0 4 0 3 3 1 3");
    input >> *trap;
    
    EXPECT_EQ(array.getSize(), 0);
    array.addFigure(trap);
    EXPECT_EQ(array.getSize(), 1);
}

TEST(ArrayTest, AddRhombus) {
    Array array(5);
    
    Rhombus* rhombus = new Rhombus();
    std::stringstream input("0 0 2 3 4 0 2 -3");
    input >> *rhombus;
    
    EXPECT_EQ(array.getSize(), 0);
    array.addFigure(rhombus);
    EXPECT_EQ(array.getSize(), 1);
}

TEST(ArrayTest, AddPentagon) {
    Array array(5);
    
    Pentagon* pentagon = new Pentagon();
    std::stringstream input("0 0 2 0 2.5 1.5 1 2.5 -0.5 1.5");
    input >> *pentagon;
    
    EXPECT_EQ(array.getSize(), 0);
    array.addFigure(pentagon);
    EXPECT_EQ(array.getSize(), 1);
}

TEST(ArrayTest, RemoveTrapezoid) {
    Array array(5);
    
    Trapezoid* trap = new Trapezoid();
    std::stringstream input("0 0 4 0 3 3 1 3");
    input >> *trap;
    
    array.addFigure(trap);
    EXPECT_EQ(array.getSize(), 1);
    
    array.deleteFigure(0);
    EXPECT_EQ(array.getSize(), 0);
}

TEST(ArrayTest, TotalArea) {
    Array array(5);
    
    Trapezoid* trap = new Trapezoid();
    std::stringstream input1("0 0 4 0 3 3 1 3");
    input1 >> *trap;
    array.addFigure(trap);
    
    Rhombus* rhombus = new Rhombus();
    std::stringstream input2("0 0 2 3 4 0 2 -3");
    input2 >> *rhombus;
    array.addFigure(rhombus);
    
    EXPECT_NEAR(array.areaOfAllFigures(), 21.0, 1e-6);
}

TEST(ArrayTest, OverflowMoment) {
    Array array(2);
    
    Trapezoid* trap1 = new Trapezoid();
    std::stringstream input1("0 0 4 0 3 3 1 3");
    input1 >> *trap1;
    
    Rhombus* rhombus = new Rhombus();
    std::stringstream input2("0 0 2 3 4 0 2 -3");
    input2 >> *rhombus;
    
    array.addFigure(trap1);
    array.addFigure(rhombus);
    
    Pentagon* pentagon = new Pentagon();
    std::stringstream input3("0 0 2 0 2.5 1.5 1 2.5 -0.5 1.5");
    input3 >> *pentagon;
    
    EXPECT_THROW(array.addFigure(pentagon), std::overflow_error);
}

TEST(ComparisonTest, TrapezoidRavenstvo) {
    Trapezoid trap1, trap2;
    std::stringstream input1("0 0 4 0 3 3 1 3");
    std::stringstream input2("0 0 4 0 3 3 1 3");
    
    input1 >> trap1;
    input2 >> trap2;
    
    EXPECT_TRUE(trap1 == trap2);
}

TEST(ComparisonTest, RhombusRavenstvo) {
    Rhombus rhombus1, rhombus2;
    std::stringstream input1("0 0 2 3 4 0 2 -3");
    std::stringstream input2("0 0 2 3 4 0 2 -3");
    
    input1 >> rhombus1;
    input2 >> rhombus2;
    
    EXPECT_TRUE(rhombus1 == rhombus2);
}

TEST(ComparisonTest, PentagonRavenstvo) {
    Pentagon pentagon1, pentagon2;
    std::stringstream input1("0 0 2 0 2.5 1.5 1 2.5 -0.5 1.5");
    std::stringstream input2("0 0 2 0 2.5 1.5 1 2.5 -0.5 1.5");
    
    input1 >> pentagon1;
    input2 >> pentagon2;
    
    EXPECT_TRUE(pentagon1 == pentagon2);
}
