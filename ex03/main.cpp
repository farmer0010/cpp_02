#include <iostream> // 표준 입출력을 사용하기 위한 헤더 파일 (std::cout, std::endl 등)
#include "Point.hpp" // Point 클래스 정의가 담긴 헤더 파일 포함

// test_bsp 함수: BSP 테스트를 수행하고 결과를 출력하는 헬퍼 함수
// Point 객체들을 상수 참조(const &)로 받아서 불필요한 복사를 방지하고 원본 값을 보호합니다.
// (이 부분은 이전 대화에서 수정되어야 할 부분입니다. 현재 코드는 여전히 값으로 받고 있습니다.)
void test_bsp(Point const &a, Point const &b, Point const &c, Point const &p, const std::string& test_name) {
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
    // const Point 객체로 선언하여 값이 변경되지 않도록 함
    Point const a(0.0f, 0.0f);
    Point const b(10.0f, 0.0f);
    Point const c(0.0f, 10.0f);

    std::cout << "Starting BSP tests..." << std::endl; // 테스트 시작 메시지
    std::cout << "---------------------------------" << std::endl << std::endl; // 구분선

    // 1. 삼각형 내부에 있는 점들에 대한 테스트
    test_bsp(a, b, c, Point(1.0f, 1.0f), "Test 1: Inside Point (1,1)");
    test_bsp(a, b, c, Point(5.0f, 2.0f), "Test 2: Inside Point (5,2)");
    test_bsp(a, b, c, Point(1.0f, 5.0f), "Test 3: Inside Point (1,5)");

    // 2. 삼각형 외부에 있는 점들에 대한 테스트
    test_bsp(a, b, c, Point(11.0f, 1.0f), "Test 4: Outside Point (11,1)");
    test_bsp(a, b, c, Point(-1.0f, 1.0f), "Test 5: Outside Point (-1,1)");
    test_bsp(a, b, c, Point(1.0f, 11.0f), "Test 6: Outside Point (1,11)");
    test_bsp(a, b, c, Point(5.0f, 5.0f), "Test 7: Outside Point (5,5) - On edge C-B"); // x+y=10 선 위에 있는 점
    test_bsp(a, b, c, Point(10.0f, 10.0f), "Test 8: Outside Point (10,10)"); // 삼각형 경계를 훨씬 벗어난 점

    // 3. 삼각형의 꼭짓점이나 변(엣지) 위에 있는 점들에 대한 테스트
    // 과제 요구사항에 따라 이 경우들은 모두 False를 반환해야 합니다.
    test_bsp(a, b, c, Point(0.0f, 0.0f), "Test 9: On Vertex A(0,0)"); // 꼭짓점 A
    test_bsp(a, b, c, Point(5.0f, 0.0f), "Test 10: On Edge A-B (5,0)"); // 변 A-B 위에 있는 점
    test_bsp(a, b, c, Point(0.0f, 5.0f), "Test 11: On Edge A-C (0,5)"); // 변 A-C 위에 있는 점
    test_bsp(a, b, c, Point(2.0f, 8.0f), "Test 12: On Edge B-C (2,8)"); // 변 B-C 위에 있는 점 (2 + 8 = 10 이므로 x+y=10 선 위에 있음)

    // 4. 아주 작은 삼각형에 대한 테스트
    Point const a2(0.0f, 0.0f);
    Point const b2(1.0f, 0.0f);
    Point const c2(0.0f, 1.0f);
    test_bsp(a2, b2, c2, Point(0.1f, 0.1f), "Test 13: Small Triangle Inside (0.1,0.1)");
    test_bsp(a2, b2, c2, Point(0.5f, 0.5f), "Test 14: Small Triangle On Edge (0.5,0.5)"); // False (경계선 위)
    test_bsp(a2, b2, c2, Point(0.9f, 0.9f), "Test 15: Small Triangle Outside (0.9,0.9)"); // False (경계선 밖)

    // 5. 음수 좌표를 포함하는 삼각형에 대한 테스트
    Point const a3(-5.0f, -5.0f);
    Point const b3(5.0f, -5.0f);
    Point const c3(0.0f, 5.0f);
    test_bsp(a3, b3, c3, Point(0.0f, 0.0f), "Test 16: Negative Coord Inside (0,0)");
    test_bsp(a3, b3, c3, Point(10.0f, 0.0f), "Test 17: Negative Coord Outside (10,0)");

    std::cout << "---------------------------------" << std::endl; // 구분선
    std::cout << "All BSP tests completed." << std::endl; // 테스트 완료 메시지

    return 0; // 프로그램 정상 종료
}
