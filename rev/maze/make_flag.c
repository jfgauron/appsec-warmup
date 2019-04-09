#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char func1(char val, char delta) {
    return val + delta;
}

char func2(char val, char delta) {
    return val - delta;
}

char func3(char val, char delta) {
    return val ^ delta;
}

char func4(char val, char delta) {
	val = func3(val, 132);
	val = func2(val, 10);
	val = func2(val, 145);
	val = func2(val, 12);
	val = func2(val, 242);
	val = func1(val, 25);
	val = func2(val, 162);
	val = func1(val, 206);
	val = func2(val, 15);
	val = func1(val, 136);
	val = func3(val, 79);
	val = func1(val, 9);
	val = func1(val, 136);
	val = func1(val, 189);
	val = func1(val, 16);
	val = func3(val, 95);
	val = func2(val, 180);
	return val;
}

char func5(char val, char delta) {
	val = func1(val, 221);
	val = func1(val, 179);
	val = func3(val, 177);
	val = func4(val, 83);
	val = func2(val, 158);
	val = func3(val, 183);
	val = func1(val, 10);
	val = func1(val, 26);
	val = func2(val, 242);
	val = func3(val, 42);
	val = func3(val, 125);
	val = func3(val, 174);
	val = func2(val, 78);
	val = func3(val, 162);
	val = func3(val, 210);
	val = func3(val, 23);
	val = func2(val, 29);
	return val;
}

char func6(char val, char delta) {
	val = func5(val, 154);
	val = func3(val, 113);
	val = func5(val, 26);
	val = func3(val, 100);
	val = func3(val, 126);
	val = func5(val, 153);
	val = func1(val, 127);
	val = func1(val, 2);
	val = func4(val, 8);
	val = func1(val, 221);
	val = func5(val, 60);
	val = func5(val, 118);
	val = func4(val, 90);
	val = func5(val, 53);
	val = func5(val, 122);
	val = func2(val, 189);
	val = func3(val, 33);
	return val;
}

char func7(char val, char delta) {
	val = func2(val, 130);
	val = func1(val, 191);
	val = func1(val, 14);
	val = func6(val, 84);
	val = func6(val, 214);
	val = func1(val, 179);
	val = func6(val, 254);
	val = func2(val, 216);
	val = func1(val, 114);
	val = func3(val, 9);
	val = func3(val, 242);
	val = func5(val, 178);
	val = func5(val, 86);
	val = func6(val, 250);
	val = func3(val, 65);
	val = func5(val, 194);
	val = func4(val, 87);
	return val;
}

char func8(char val, char delta) {
	val = func6(val, 170);
	val = func3(val, 192);
	val = func1(val, 12);
	val = func2(val, 83);
	val = func4(val, 112);
	val = func2(val, 251);
	val = func5(val, 47);
	val = func6(val, 222);
	val = func6(val, 87);
	val = func6(val, 156);
	val = func1(val, 122);
	val = func4(val, 54);
	val = func7(val, 6);
	val = func2(val, 144);
	val = func4(val, 58);
	val = func5(val, 75);
	val = func3(val, 77);
	return val;
}

char func9(char val, char delta) {
	val = func8(val, 100);
	val = func4(val, 163);
	val = func5(val, 153);
	val = func6(val, 10);
	val = func6(val, 221);
	val = func7(val, 4);
	val = func8(val, 113);
	val = func4(val, 141);
	val = func4(val, 228);
	val = func4(val, 0);
	val = func7(val, 124);
	val = func3(val, 145);
	val = func2(val, 79);
	val = func1(val, 245);
	val = func3(val, 177);
	val = func8(val, 39);
	val = func6(val, 29);
	return val;
}

char func10(char val, char delta) {
	val = func2(val, 204);
	val = func2(val, 222);
	val = func7(val, 76);
	val = func1(val, 144);
	val = func1(val, 247);
	val = func3(val, 43);
	val = func2(val, 143);
	val = func4(val, 14);
	val = func5(val, 170);
	val = func1(val, 22);
	val = func7(val, 25);
	val = func4(val, 136);
	val = func9(val, 254);
	val = func2(val, 82);
	val = func6(val, 79);
	val = func9(val, 241);
	val = func9(val, 39);
	return val;
}

char func11(char val, char delta) {
	val = func8(val, 115);
	val = func2(val, 13);
	val = func1(val, 195);
	val = func4(val, 132);
	val = func6(val, 139);
	val = func7(val, 127);
	val = func10(val, 36);
	val = func6(val, 165);
	val = func1(val, 230);
	val = func9(val, 30);
	val = func10(val, 205);
	val = func5(val, 168);
	val = func8(val, 195);
	val = func9(val, 143);
	val = func10(val, 147);
	val = func10(val, 6);
	val = func5(val, 42);
	return val;
}

char func12(char val, char delta) {
	val = func3(val, 137);
	val = func10(val, 151);
	val = func11(val, 92);
	val = func7(val, 162);
	val = func3(val, 62);
	val = func6(val, 134);
	val = func4(val, 128);
	val = func10(val, 34);
	val = func8(val, 219);
	val = func7(val, 60);
	val = func6(val, 143);
	val = func9(val, 251);
	val = func2(val, 53);
	val = func11(val, 213);
	val = func9(val, 150);
	val = func10(val, 205);
	val = func6(val, 109);
	return val;
}

char func13(char val, char delta) {
	val = func11(val, 174);
	val = func2(val, 9);
	val = func1(val, 38);
	val = func9(val, 25);
	val = func6(val, 42);
	val = func9(val, 152);
	val = func9(val, 56);
	val = func10(val, 187);
	val = func12(val, 120);
	val = func12(val, 116);
	val = func6(val, 107);
	val = func1(val, 132);
	val = func5(val, 227);
	val = func2(val, 193);
	val = func1(val, 186);
	val = func2(val, 22);
	val = func9(val, 121);
	return val;
}

char func14(char val, char delta) {
	val = func9(val, 188);
	val = func9(val, 102);
	val = func5(val, 76);
	val = func10(val, 238);
	val = func8(val, 93);
	val = func6(val, 89);
	val = func3(val, 28);
	val = func9(val, 228);
	val = func8(val, 198);
	val = func5(val, 184);
	val = func10(val, 17);
	val = func4(val, 101);
	val = func10(val, 77);
	val = func3(val, 2);
	val = func1(val, 138);
	val = func5(val, 132);
	val = func13(val, 154);
	return val;
}

char func15(char val, char delta) {
	val = func8(val, 28);
	val = func8(val, 123);
	val = func6(val, 204);
	val = func4(val, 179);
	val = func5(val, 242);
	val = func5(val, 120);
	val = func12(val, 223);
	val = func13(val, 167);
	val = func7(val, 138);
	val = func11(val, 181);
	val = func5(val, 139);
	val = func1(val, 144);
	val = func12(val, 103);
	val = func3(val, 8);
	val = func13(val, 97);
	val = func7(val, 214);
	val = func10(val, 11);
	return val;
}

char func16(char val, char delta) {
	val = func6(val, 9);
	val = func1(val, 171);
	val = func1(val, 125);
	val = func7(val, 12);
	val = func11(val, 245);
	val = func8(val, 182);
	val = func13(val, 4);
	val = func13(val, 214);
	val = func1(val, 176);
	val = func6(val, 61);
	val = func7(val, 238);
	val = func7(val, 219);
	val = func2(val, 16);
	val = func13(val, 26);
	val = func15(val, 59);
	val = func1(val, 56);
	val = func11(val, 251);
	return val;
}

char func17(char val, char delta) {
	val = func4(val, 128);
	val = func9(val, 130);
	val = func7(val, 240);
	val = func1(val, 247);
	val = func1(val, 22);
	val = func16(val, 231);
	val = func4(val, 181);
	val = func7(val, 78);
	val = func10(val, 217);
	val = func16(val, 22);
	val = func10(val, 180);
	val = func9(val, 115);
	val = func15(val, 12);
	val = func16(val, 243);
	val = func14(val, 114);
	val = func4(val, 169);
	val = func9(val, 233);
	return val;
}

char func18(char val, char delta) {
	val = func15(val, 126);
	val = func17(val, 164);
	val = func1(val, 129);
	val = func5(val, 241);
	val = func15(val, 40);
	val = func1(val, 3);
	val = func17(val, 153);
	val = func7(val, 52);
	val = func12(val, 19);
	val = func8(val, 214);
	val = func7(val, 56);
	val = func2(val, 180);
	val = func14(val, 168);
	val = func6(val, 27);
	val = func15(val, 25);
	val = func16(val, 252);
	val = func10(val, 223);
	return val;
}

char func19(char val, char delta) {
	val = func3(val, 141);
	val = func15(val, 221);
	val = func4(val, 76);
	val = func14(val, 167);
	val = func10(val, 252);
	val = func4(val, 171);
	val = func10(val, 242);
	val = func11(val, 154);
	val = func5(val, 70);
	val = func6(val, 172);
	val = func18(val, 125);
	val = func17(val, 161);
	val = func8(val, 166);
	val = func15(val, 158);
	val = func7(val, 210);
	val = func8(val, 198);
	val = func15(val, 224);
	return val;
}

char func20(char val, char delta) {
	val = func4(val, 223);
	val = func2(val, 42);
	val = func14(val, 251);
	val = func6(val, 74);
	val = func6(val, 89);
	val = func13(val, 231);
	val = func13(val, 133);
	val = func4(val, 70);
	val = func2(val, 167);
	val = func5(val, 135);
	val = func9(val, 92);
	val = func11(val, 132);
	val = func12(val, 210);
	val = func11(val, 122);
	val = func18(val, 54);
	val = func9(val, 61);
	val = func12(val, 136);
	return val;
}


int main() {
	char* flag = "FLAG{6f0a2b96ec896f7123e200b1eb85c8e8}";
    char target[64] = {0};

    for (int i = 0; i < strlen(flag); i++) {
        target[i] = func20(flag[i], i);
    }

    printf("char target[] = {0x%x", target[0] & 0xff);
    for (int i = 1; i < strlen(target); i++) {
        printf(", 0x%x", target[i] & 0xff);
    }
    printf("};");

	return 1;
}
