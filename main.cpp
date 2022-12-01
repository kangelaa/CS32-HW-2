//
//  main.cpp
//  HW2
//
//  Created by Angela Kan on 2/1/21.
//
//
//#include <iostream>
//#include <string>
//#include <stack>
//#include <cassert>
//#include <cctype>
//using namespace std;
//
////tests for eval
//int main()
//{
//    bool ba[10] = {
//      //  0      1      2      3      4      5      6      7      8      9
//        true,  true,  true,  false, false, false, true,  false, true,  false
//    };
//    string pf;
//    bool answer;
//    assert(evaluate("  2", ba, pf, answer) == 0 && answer);
//    assert(evaluate("(3  )", ba, pf, answer) == 0 && !answer);
//    assert(evaluate("2&(3)", ba, pf, answer) == 0 && !answer);
//    assert(evaluate("0 & !9", ba, pf, answer) == 0 && answer);
//    assert(evaluate("!(7|8)", ba, pf, answer) == 0 &&!answer);
//    assert(evaluate("!7|8", ba, pf, answer) == 0 && answer);
//    assert(evaluate("6|4&5", ba, pf, answer) == 0 && answer);
//    assert(evaluate("1&!(9|1&1|9) | !!!(9&1&9)", ba, pf, answer) == 0 && answer);
//
//    assert(evaluate("2| 3", ba, pf, answer) == 0  &&  pf == "23|" &&  answer);
//    assert(evaluate("😎", ba, pf, answer) == 1);
//    assert(evaluate(" &6", ba, pf, answer) == 1);
//    assert(evaluate("4 5", ba, pf, answer) == 1);
//    assert(evaluate("01", ba, pf, answer) == 1);
//    assert(evaluate("()", ba, pf, answer) == 1);
//    assert(evaluate("()4", ba, pf, answer) == 1);
//    assert(evaluate("2(9|8)", ba, pf, answer) == 1);
//    assert(evaluate("2(&8)", ba, pf, answer) == 1);
//    assert(evaluate("(6&(7|7)", ba, pf, answer) == 1);
//    assert(evaluate("x+5", ba, pf, answer) == 1);
//    assert(evaluate("", ba, pf, answer) == 1);
//    assert(evaluate("2|3|4", ba, pf, answer) == 0
//                           &&  pf == "23|4|"  &&  answer);
//    assert(evaluate("2|(3|4)", ba, pf, answer) == 0
//                           &&  pf == "234||"  &&  answer);
//    assert(evaluate("4  |  !3 & (0&3) ", ba, pf, answer) == 0
//                           &&  pf == "43!03&&|"  &&  !answer);
//    assert(evaluate(" 9  ", ba, pf, answer) == 0  &&  pf == "9"  &&  !answer);
//    ba[2] = false;
//    ba[9] = true;
//    assert(evaluate("((9))", ba, pf, answer) == 0  &&  pf == "9"  &&  answer);
//    assert(evaluate("3&!!4", ba, pf, answer) == 0  &&  pf == "34!!&"  &&  !answer);
//    assert(evaluate("3&(!!4)", ba, pf, answer) == 0  &&  pf == "34!!&"  &&  !answer);
//    assert(evaluate("3&()!!4", ba, pf, answer) == 1  &&  pf == "34!!&"  &&  !answer);
//    assert(evaluate("3&!!4)", ba, pf, answer) == 1  &&  pf == "34!!&"  &&  !answer);
//    assert(evaluate("(3)&!!(4)", ba, pf, answer) == 0  &&  pf == "34!!&"  &&  !answer);
//    assert(evaluate("3(&!!)4", ba, pf, answer) == 1  &&  pf == "34!!&"  &&  !answer);
//    assert(evaluate("3(((&!!)))4", ba, pf, answer) == 1  &&  pf == "34!!&"  &&  !answer);
//    assert(evaluate("3&((!!4)", ba, pf, answer) == 1  &&  pf == "34!!&"  &&  !answer);
//    assert(evaluate("((3)&!!(4))", ba, pf, answer) == 0  &&  pf == "34!!&"  &&  !answer);
//    assert(evaluate("3&&4", ba, pf, answer) == 1  &&  pf == "34!!&"  &&  !answer);
//    assert(evaluate("2| 3", ba, pf, answer) == 0  &&  pf == "23|" &&  !answer);
//    assert(evaluate("!!( 3 & 4 )", ba, pf, answer) == 0 && !answer);
//
//    string a = "8&8"; // valid
//    string b = "!!3|!4"; // valid
//    string c = "1|2)"; // invalid
//    string d = "(1&2("; // invalid
//    string e = "((!1|2)|3&4)"; // valid
//    string f = "3|(3+4)"; // invalid
//    string g = "3|3& 4"; // valid
//    string h = "            &8"; //invalid
//    string i = "!(3&4)|!(5|6)&(2|(1&2))"; // valid
//    string s = "!!( (3) & (4) )";  // valid
//    string t = "4 | !!3 & (0 & 3)"; // valid
//    string u = "&8&"; // invalid
//    string v = "!8"; // valid
//    string w = "88&1"; // invalid
//    string x = "8&&&&"; // invalid
//    string y = "8|&2"; // invalid
//    string z = "((8)&(2))|!3"; // valid
//    string zz;
//    string yy = "1&!(9|1&1|9) | !!!(9&1&9)";
//    string xx = "(!)!!1";
//    bool arr[10] = { true, true, true, true, false, true, false, true, true, false };
//    bool ab;
//    assert(evaluate(xx, arr, zz, ab) == 1);
//    assert(evaluate(yy, arr, zz, ab) == 0 && zz == "1911&|9|!&91&9&!!!|" && ab);
//    assert(evaluate(a, arr, zz, ab) == 0 && zz == "88&");
//    assert(evaluate(b, arr, zz, ab) == 0 && zz == "3!!4!|");
//    assert(evaluate(c, arr, zz, ab) == 1);
//    assert(evaluate(d, arr, zz, ab) == 1);
//    assert(evaluate(e, arr, zz, ab) == 0 && zz == "1!2|34&|");
//    assert(evaluate(f, arr, zz, ab) == 1);
//    assert(evaluate(g, arr, zz, ab) == 0);
//    assert(evaluate(h, arr, zz, ab) == 1);
//    assert(evaluate(i, arr, zz, ab) == 0 && zz == "34&!56|!212&|&|");
//    assert(evaluate(s, arr, zz, ab) == 0 && zz == "34&!!");
//    assert(evaluate(t, arr, zz, ab) == 0 && zz == "43!!03&&|");
//    assert(evaluate(u, arr, zz, ab) == 1);
//    assert(evaluate(v, arr, zz, ab) == 0 && zz == "8!");
//    assert(evaluate(w, arr, zz, ab) == 1);
//    assert(evaluate(x, arr, zz, ab) == 1);
//    assert(evaluate(y, arr, zz, ab) == 1);
//    assert(evaluate(z, arr, zz, ab) == 0 && zz == "82&3!|");
//
//    pf = "";
//    answer=true;
//
//    ba[2] = false;
//    ba[9] = true;
//    assert(evaluate("((9))", ba, pf, answer) == 0 && pf == "9" && answer);
//    assert(evaluate("2| 3", ba, pf, answer) == 0 && pf == "23|" && !answer);
//    assert(evaluate("!!!(8)", ba, pf, answer) == 0 && pf == "8!!!" && !answer);
//    assert(evaluate("3&(    4|3)", ba, pf, answer) == 0 && pf == "343|&" && !answer);
//    assert(evaluate("  3&(    4|3)", ba, pf, answer) == 0 && pf == "343|&" && !answer);
//    assert(evaluate("3&(    4|3(", ba, pf, answer) == 1 && pf == "343|&" && !answer);
//    assert(evaluate("     ", ba, pf, answer) == 1 && pf == "343|&" && !answer);
//    assert(evaluate("4|(3&3&3)&!!1", ba, pf, answer) == 0 && pf == "433&3&1!!&|" && !answer);
//    assert(evaluate("3&", ba, pf, answer) == 1 && pf == "433&3&1!!&|" && !answer);
//    assert(evaluate("0", ba, pf, answer) == 0 && pf == "0" && answer);
//    assert(evaluate("  3 & !4     ", ba, pf, answer) == 0 && pf == "34!&" && !answer);
//    assert(evaluate("!3!", ba, pf, answer) == 1 && pf == "34!&" && !answer);
//    assert(evaluate("(3&3!)", ba, pf, answer) == 1 && pf == "34!&" && !answer);
//    assert(evaluate("3*3", ba, pf, answer) == 1 && pf == "34!&" && !answer);
//    assert(evaluate("1&&2", ba, pf, answer) == 1 && pf == "34!&" && !answer);
//
//    cout << "Passed all tests" << endl;
//}
