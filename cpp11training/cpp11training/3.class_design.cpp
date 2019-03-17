#include "stdafx.h"

#include <gtest/gtest.h>

#include "class_design/Thing.h"
#include "class_design/Instrument.h"
#include "class_design/Piano.h"
#include "class_design/Vehicle.h"
#include "class_design/MyBike.h"

#include <utility>

// Question from the class:
// Uniform Initialization: can you specify a member variable default with braces?
//   --> Yes.  It's called a "brace-or-equal-initializer"
//   cf. https://arne-mertz.de/2015/08/new-c-features-default-initializers-for-member-variables/
//
class Person {
public:
    int birthyear = 1900; // <-- equal-initializer
    std::string name{"John"}; // <-- brace-initializer
    std::string given_name{"Doe"};
};

class Child : public Person {
public:
    Child(Person parent, int n, std::string name)
        : Person{n, std::move(name), std::move(parent.given_name)}
    {}
};

TEST(member_initializers, defaults_can_be_specified_in_class) {
    Person x;
    EXPECT_EQ(1900, x.birthyear);
    EXPECT_EQ("John", x.name);

    Person me{1976, "xtofl", "drarip"};
    EXPECT_EQ(1976, me.birthyear);
    EXPECT_EQ("xtofl", me.name);

    Child c{me, 2002, "Natan"};
    EXPECT_EQ("drarip", c.given_name);
}

// TODO:
// visit Thing.h, and rename Thing::size_in_cm to size_in_m.
// The code still compiles.  That's bad.  Make it so that inheritors
// don't compile by accident.
//
// GOAL: learn to conciously design a class for inheritance
//
// HINT: use the `override` keyword

TEST(class_design, DISABLED_adding_constructors_should_be_trivial)
{
    // TODO: add a constructor Thing(std::string)
    // make Piano and MyBike inherit this constructor with the least amount of code
    // and replication
    //
    // GOAL: make it trivial to add a base class constructors like Thing::Thing(std::string name)
    //
    // HINT: `using` is the key
    Piano p; // { "my piano" };
    MyBike b; // { "my bike" };

    EXPECT_EQ("making music", p.purpose());
	EXPECT_EQ("my piano", p.name());

	EXPECT_EQ("transporting", b.purpose());
	EXPECT_NEAR(60.0, b.size_in_cm(), 0.00001);
}

// TODO: alter the needed classes to make it impossible to copy things
// GOAL: learn to use `delete` qualifier
TEST(class_design, DISABLED_synthesized_functions)
{
    Piano p; // { "" };
	auto q = p; // should not compile.
}
