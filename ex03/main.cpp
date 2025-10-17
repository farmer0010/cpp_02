#include <iostream>
#include "Point.hpp" // Fixed.hpp가 Point.hpp에 포함되어 있으므로 이것만 포함해도 됩니다.

// bsp 함수의 선언을 여기에서도 해주는 것이 좋습니다. (혹은 Point.hpp에 이미 있으므로 생략 가능)
// bool bsp( Point const a, Point const b, Point const c, Point const point);

// 테스트 결과를 출력해주는 헬퍼 함수
void test_bsp(Point const a, Point const b, Point const c, Point const p, const std::string& test_name) {
    std::cout << "--- " << test_name << " ---" << std::endl;
    std::cout << "Triangle vertices: A(" << a.getX() << ", " << a.getY() << ")";
    std::cout << ", B(" << b.getX() << ", " << b.getY() << ")";
    std::cout << ", C(" << c.getX() << ", " << c.getY() << ")" << std::endl;
    std::cout << "Point P: (" << p.getX() << ", " << p.getY() << ")" << std::endl;
    if (bsp(a, b, c, p)) {
        std::cout << "Result: Point is INSIDE the triangle." << std::endl;
    } else {
        std::cout << "Result: Point is OUTSIDE the triangle." << std::endl;
    }
    std::cout << std::endl;
}


int main(void) {
    // 삼각형 정의: A(0,0), B(10,0), C(0,10)
    Point const a(0.0f, 0.0f);
    Point const b(10.0f, 0.0f);
    Point const c(0.0f, 10.0f);

    std::cout << "Starting BSP tests..." << std::endl;
    std::cout << "---------------------------------" << std::endl << std::endl;

    // 1. 내부 점
    test_bsp(a, b, c, Point(1.0f, 1.0f), "Test 1: Inside Point (1,1)");
    test_bsp(a, b, c, Point(5.0f, 2.0f), "Test 2: Inside Point (5,2)");
    test_bsp(a, b, c, Point(1.0f, 5.0f), "Test 3: Inside Point (1,5)");

    // 2. 외부 점
    test_bsp(a, b, c, Point(11.0f, 1.0f), "Test 4: Outside Point (11,1)");
    test_bsp(a, b, c, Point(-1.0f, 1.0f), "Test 5: Outside Point (-1,1)");
    test_bsp(a, b, c, Point(1.0f, 11.0f), "Test 6: Outside Point (1,11)");
    test_bsp(a, b, c, Point(5.0f, 5.0f), "Test 7: Outside Point (5,5) - On edge C-B");
    test_bsp(a, b, c, Point(10.0f, 10.0f), "Test 8: Outside Point (10,10)"); // outside triangle bounds

    // 3. 엣지 위의 점 (과제 요구사항: False 반환해야 함)
    test_bsp(a, b, c, Point(0.0f, 0.0f), "Test 9: On Vertex A(0,0)");
    test_bsp(a, b, c, Point(5.0f, 0.0f), "Test 10: On Edge A-B (5,0)");
    test_bsp(a, b, c, Point(0.0f, 5.0f), "Test 11: On Edge A-C (0,5)");
    test_bsp(a, b, c, Point(2.0f, 8.0f), "Test 12: On Edge B-C (2,8)"); // 2 + 8 = 10 (on line x+y=10)

    // 4. 아주 작은 삼각형
    Point const a2(0.0f, 0.0f);
    Point const b2(1.0f, 0.0f);
    Point const c2(0.0f, 1.0f);
    test_bsp(a2, b2, c2, Point(0.1f, 0.1f), "Test 13: Small Triangle Inside (0.1,0.1)");
    test_bsp(a2, b2, c2, Point(0.5f, 0.5f), "Test 14: Small Triangle On Edge (0.5,0.5)"); // False
    test_bsp(a2, b2, c2, Point(0.9f, 0.9f), "Test 15: Small Triangle Outside (0.9,0.9)"); // False

    // 5. 음수 좌표 포함 삼각형
    Point const a3(-5.0f, -5.0f);
    Point const b3(5.0f, -5.0f);
    Point const c3(0.0f, 5.0f);
    test_bsp(a3, b3, c3, Point(0.0f, 0.0f), "Test 16: Negative Coord Inside (0,0)");
    test_bsp(a3, b3, c3, Point(10.0f, 0.0f), "Test 17: Negative Coord Outside (10,0)");

    std::cout << "---------------------------------" << std::endl;
    std::cout << "All BSP tests completed." << std::endl;

    return 0;
}
