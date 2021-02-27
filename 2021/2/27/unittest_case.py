from unittest import (
    TestCase,
    TestSuite,
    TextTestResult,
    TextTestRunner, 
    )
import unittest

class TestCase1(TestCase):
    def setUp(self) -> None:
        return super().setUp()

    def tearDown(self) -> None:
        return super().tearDown()

    def test_add(self):
        self.assertEqual(4 + 5, 9)
        self.assertEqual(4 + 6, 10)
    

if __name__ == "__main__":
    unittest.main()