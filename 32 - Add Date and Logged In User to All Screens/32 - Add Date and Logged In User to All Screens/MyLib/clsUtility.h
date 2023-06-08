#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#define M_PI 3.14159265358979323846

using namespace std;

class clsUtility
{
public:
	enum enNumberType { Odd = 1, Even = 2 };
    static enNumberType CheckOddOrEven(int Num)
    {
        if (Num % 2 == 0)
            return Even;
        else
            return Odd;
    }
    static void PrintNumberType(enNumberType NumberType)
    {
        if (NumberType == Even)
            cout << "The Number is: Even\n";
        else
            cout << "The Number is: Odd\n";
    }

    static float ReadNumber(string msg)
    {
        float Number;
        cout << msg;
        cin >> Number;
        return Number;
    }
    static float HalfNumber(float Number)
    {
        return Number / 2;
    }
    static void printHalfNumber(float Number)
    {
        cout << "Half of " << Number << " is : " << HalfNumber(Number) << endl;
    }

    enum enPassFail { Pass = 1, Fail = 2 };
    static enPassFail CheckMark(int num)
    {
        if (num >= 50)
            return Pass;
        else
            return Fail;
    }
    static void PrintPassFail(int Num)
    {
        if (CheckMark(Num) == Pass)
            cout << "\nPass\n";

        else
            cout << "\nFail\n";
    }

    static float SumOf3Numbers(float Num1, float Num2, float Num3)
    {
        return Num1 + Num2 + Num3;
    }

    static float CalculatAvrege(int Num1, int Num2, int Num3)
    {
        return  SumOf3Numbers(Num1, Num2, Num3) / 3;
    }

    static float CheckTheMaxNum(float Num1, float Num2)
    {
        if (Num1 > Num2)
            return Num1;
        else
            return Num2;
    }

    static float CheckTheMaxNum(float Num1, float Num2, float Num3)
    {
        if (Num1 > Num2)
        {
            if (Num1 > Num3)
                return Num1;
            else
                return Num3;
        }

        else
        {
            if (Num2 > Num3)
                return Num2;
            else
                return Num3;
        }
    }

    static void Swap2Numbers(int& Num1, int& Num2)
    {
        int Temp;
        Temp = Num1;
        Num1 = Num2;
        Num2 = Temp;
    }

    static float RectangleAreaLengthWidth(float Length, float Width)
    {
        return Length * Width;
    }

    static float RectangleAreaDiagonalSide(float Diagonal, float Side)
    {
        return Side * sqrt(pow(Diagonal, 2) - pow(Side, 2));
    }

    static float RectangleArea_BaseHeight(float base, float height)
    {
        return base / 2 * height;
    }

    static float CercleArea_Ray(float Ray)
    {
        return M_PI * pow(Ray, 2);
    }

    static float CercleArea_Diameter(float Diameter)
    {
        return (M_PI * pow(Diameter, 2)) / 4;
    }

    static float CercleArea_Circumference(float Circumference)
    {
        return  pow(Circumference, 2) / (M_PI * 4);
    }

    static float CercleArea_SideBase(float Side, float base)
    {
        return  M_PI * (pow(base, 2) / 4) * ((2 * Side - base) / (2 * Side + base));
    }

    static float CercleArea_Side1Side2Base(float Side1, float Side2, float base)
    {
        float P = (Side1 + Side2 + base) / 2;
        return  M_PI * pow((Side1 * Side2 * base) / (4 * sqrt(P * (P - Side1) * (P - Side2) * (P - base))), 2);
    }

    static bool ValidateNumerInRange(float Number, float From, float To)
    {
        return Number >= From && Number <= To;
    }   

    static int SumOddNumFrom1ToN(int Num)
    {
        int Sum = 0;
        for (int i = 1; i <= Num; i++)
        {
            if (CheckOddOrEven(i) == Odd)
                Sum += i;
        }
        return Sum;
    }

    static int SumEvenNumFrom1ToN(int Num)
    {
        int Sum = 0;
        for (int i = 1; i <= Num; i++)
        {
            if (CheckOddOrEven(i) == Even)
                Sum += i;
        }
        return Sum;
    }

    static int FactorialOfNumber(int Number)
    {
        int Factorial = Number;
        for (int i = 1; i < Number; i++)
            Factorial *= i;

        return Factorial;
    }

    static int Power(int Num, int Pow)
    {
        int result = Num;
        for (int i = 1; i < Pow; i++)
            result *= Num;
        return result;
    }
    
    static string CheckGrade(int Number)
    {
        if (Number > 100)
            return "\nWrong!\n";
        else if (Number >= 90)
            return "\nYou get : A\n";
        else if (Number >= 80)
            return "\nYou get : B\n";
        else if (Number >= 70)
            return "\nYou get : C\n";
        else if (Number >= 60)
            return "\nYou get : D\n";
        else if (Number >= 50)
            return "\nYou get : E\n";
        else if (Number > -1)
            return "\nYou get : F\n";
        else
            return "\nWrong!\n";
    }

    static char GetGradeLetter(int Grade)
    {
        if (Grade >= 90)
            return 'A';
        else if (Grade >= 80)
            return 'B';
        else if (Grade >= 70)
            return 'C';
        else if (Grade >= 60)
            return 'D';
        else if (Grade >= 50)
            return 'E';
        else
            return 'F';
    }

    static float GetCommissionPercentage(float TotaleSales)
    {
        if (TotaleSales >= 1000000) {
            return 0.01;
        }
        else if (TotaleSales >= 500000) {
            return 0.02;
        }
        else if (TotaleSales >= 100000) {
            return 0.03;
        }
        else if (TotaleSales >= 50000) {
            return 0.05;
        }
        else {
            return 0;
        }
    }

    static float CalcCommissionPercentage(float TotaleSales)
    {
        return TotaleSales * GetCommissionPercentage(TotaleSales);
    }

    static struct stPiggyBankContent {
        float Penny, Nikel, Dime, Quarter, Dollar;
    };

    stPiggyBankContent ReadPiggyBankContent()
    {
        stPiggyBankContent Piggy;

        Piggy.Dollar = ReadNumber("Please enter Dollar : ");
        Piggy.Quarter = ReadNumber("Please enter Quarter : ");
        Piggy.Dime = ReadNumber("Please enter Dime : ");
        Piggy.Nikel = ReadNumber("Please enter Nikel : ");
        Piggy.Penny = ReadNumber("Please enter Penny : ");

        return Piggy;
    }

    enum enOpType
    {
        Add = '+', Sub = '-', Multiply = '*', Devide = '/'
    };

    static enOpType ReadOpType()
    {
        char OpType = '+';

        cout << "Please enter Operation Type ( + - * / ) : ";
        cin >> OpType;
        return (enOpType)OpType;
    }

    static struct SimpleCalculator
    {
        float Num1;
        enOpType OperationType;
        float Num2;
    };

    static SimpleCalculator ReadNmsAndoPeration()
    {
        SimpleCalculator Calc;
        Calc.Num1 = ReadNumber("Pleae enter Number1 : ");
        Calc.OperationType = ReadOpType();
        Calc.Num2 = ReadNumber("Pleae enter Number2 : ");
        return Calc;
    }

    static float Calculate(SimpleCalculator Calc)
    {
        switch (Calc.OperationType)
        {
        case Add: return Calc.Num1 + Calc.Num2;
        case Sub: return Calc.Num1 - Calc.Num2;
        case Multiply: return Calc.Num1 * Calc.Num2;
        case Devide: return Calc.Num1 / Calc.Num2;
        default:
            return Calc.Num1 + Calc.Num2;
        }
        /*if (Calc.OperationType == Add)
            return Calc.Num1 + Calc.Num2;
        else if (Calc.OperationType == Sub)
            return Calc.Num1 - Calc.Num2;
        else if (Calc.OperationType == Multiply)
            return Calc.Num1 * Calc.Num2;
        else
            return Calc.Num1 / Calc.Num2;*/
    }

    static float SumUntil99()
    {
        float Total = 0;
        int i = 0;
        while (true)
        {
            i++;
            float Number = ReadNumber("Please enter Number" + to_string(i) + " : ");
            if (Number == -99)
                return Total;
            Total += Number;
        }
    }

    enum enPrimeOrNot {
        Prime = 1, NotPrime = 2
    };

    static enPrimeOrNot CheckNumPrime(int Number)
    {
        if (Number == 1 || Number == 2)
            return Prime;

        for (int i = 2; i < round(Number / 2); i++)
        {
            if (Number % i == 0)
                return NotPrime;
        }
        return Prime;
    }

    static int ReadNumberInRange(string Message, int From)
    {
        int Number;
        string wrong = "";
        do {
            cout << wrong << Message;
            cin >> Number;
            wrong = "Number must be > 0!! ";
        } while (Number < From);
        return Number;
    }

    static void Print_PrimeOrNot()
    {
        string Mesg = "Please enter Number : ";
        if (CheckNumPrime(ReadNumberInRange(Mesg, 0)) == Prime)
            cout << "\nYour Number is Prime\n";
        else
            cout << "\nYour Number Not Prime\n";
    }

    static float Remainder(int Paid, int TotalBill)
    {
        return Paid - TotalBill;
    }

    static void Print_PaidRemainder()
    {
        float Rem = Remainder(ReadNumber("How much customer paid : "), ReadNumber("Please entre Total Bill : "));
        cout << "Remainder is : " << Rem;

        if (Rem < 0)
            system("color 4F");
    }

    static float TotalBille(float BilleValue)
    {
        return BilleValue * 1.10 * 1.16;
    }

    static void PrintResult()
    {
        float Total = TotalBille(ReadNumber("Please enter Totale Bille : "));
        cout << "\nTotal = " << Total << endl;

    }

    static float CalcHoursToDays(float Hours)
    {
        return Hours / 24;
    }

    static float CalcHoursToWeeks(float Hours)
    {
        return Hours / 24 / 7;
    }

    static float CalcDaysToWeeks(float Days)
    {
        return Days / 7;
    }

    static int DaysToSecends(int Days)
    {
        return Days * 24 * 60 * 60;
    }

    static int HoursToSecends(int Hours)
    {
        return Hours * 60 * 60;
    }

    static int MinitsToSecends(int Minits)
    {
        return Minits * 60;
    }

    static struct strTaskDuration
    {
        int Days, Hours, Minits, Seconds;
    };

    static strTaskDuration ReadTakDuration()
    {
        strTaskDuration Task;
        Task.Days = ReadNumber("Please enter Number of days : ");
        Task.Hours = ReadNumber("Please enter Number of Hours : ");
        Task.Minits = ReadNumber("Please enter Number of Minits : ");
        Task.Seconds = ReadNumber("Please enter Number of Seconds : ");
        return Task;
    }

    static int TaskDurationInSec(strTaskDuration Task)
    {
        return (Task.Days * 24 * 60 * 60) +
            (Task.Hours * 60 * 60) +
            (Task.Minits * 60) +
            Task.Seconds;
    }

    static strTaskDuration TaskSecToDays(int Sec)
    {
        strTaskDuration TaskDuration;
        int SecPerDay = 24 * 60 * 60, SecPerHour = 60 * 60, SecPerMinit = 60, Remander = 0;
        TaskDuration.Days = floor(Sec / SecPerDay);
        Remander = Sec % SecPerDay;
        TaskDuration.Hours = floor(Remander / SecPerHour);
        Remander = Remander % SecPerHour;
        TaskDuration.Minits = floor(Remander / SecPerMinit);
        TaskDuration.Seconds = Remander % SecPerMinit;
        return TaskDuration;
    }

    enum enDaysOfTheWeek { Manday = 1, Tusday = 2, Wednesday = 3, Thursday = 4, Friday = 5, saturday = 6, sunday = 7 };

    static int ReadNumberInRange(string Message, int From, int To)
    {
        int Number;
        do {
            cout << Message;
            cin >> Number;
        } while (Number < From || Number > To);
        return Number;
    }

    static string MyDay(int NumInRange)
    {
        switch (NumInRange)
        {
        case Manday: return "Manday";
        case Tusday: return "Tusday";
        case Wednesday: return "Wednesday";
        case Thursday: return "Thursday";
        case Friday: return "Friday";
        case saturday: return "saturday";
        case sunday: return "sunday";
        default: return "";
        }
    }

    enum enMonth
    {
        Jan = 1, Fab = 2, Mar = 3, Apr = 4, May = 5, June = 6,
        Jul = 7, Aug = 8, Sep = 9, Oct = 10, Nov = 11, Dec = 12
    };

    static string MyMonth(enMonth Month)
    {
        switch (Month)
        {
        case Jan: return "Januarary";

        case Fab: return "Fabrary";

        case Mar: return "March";

        case Apr: return "April";

        case May: return "May";

        case June: return "June";

        case Jul: return "July";

        case Aug: return "August";

        case Sep: return "September";

        case Oct: return "Octobre";

        case Nov: return "November";

        case Dec: return "December";

        default: return "";
        }
    }

    static void PrintLettersAtoZ()
    {
        for (char c = 'A'; c <= 'Z'; c++)
        {
            cout << c << endl;
        }
    }

    static int Loan_Months(int LoanAmoust, int MontlyPaid)
    {
        return LoanAmoust / MontlyPaid;
    }

    static float Loan_MonthlyPaid(int Loanamount, int Months)
    {
        return (float)Loanamount / Months;
    }

    static void PrintTableHeader() {

        cout << endl;

        for (int i = 0; i < 3; i++)
            cout << "\t";

        cout << "Multiplication Table From 1 to 10\n\n";

        for (int i = 1; i <= 10; i++)
            cout << "\t" << i;

        cout << endl;

        for (int i = 0; i < 85; i++)
            cout << "_";

        cout << endl;
    }

    static string Colum(int i) {

        string Colum = "";
        if (i != 10)
            Colum = to_string(i) + "   |";
        else
            Colum = to_string(i) + "  |";

        for (int j = 1; j <= 10; j++)
        {
            Colum = Colum + "\t" + to_string(i * j);
        }
        return Colum;
    }

    static void PrintMultiplicationTable() {

        PrintTableHeader();

        for (int i = 1; i <= 10; i++)
            cout << Colum(i) << endl;
    }

    static bool CheckPerfect(int Number)
    {
        int sum = 0;
        for (int i = 1; i < Number; i++)
        {
            if (Number % i == 0)
            {
                sum += i;
            }
        }

        return sum == Number;
    }

    static void PrintReversedDigits(int Number)
    {
        while (Number > 0)
        {
            cout << (Number % 10) << endl;
            Number = Number / 10;
        }
    }

    static void SumOfDigits(int Number)
    {
        int sum = 0;
        while (Number > 0)
        {
            sum += (Number % 10);
            Number = Number / 10;
        }
        cout << "Result = " << sum << endl;
    }

    static int ReversNum(int Number)
    {
        int RevNum = 0;
        while (Number > 0)
        {
            RevNum = (RevNum * 10) + (Number % 10);
            Number = Number / 10;
        }
        return RevNum;
    }

    static int DigitFrequency(int Number, short Digit)
    {
        int sum = 0;
        while (Number > 0)
        {
            if (Number % 10 == Digit)
                sum++;
            Number = Number / 10;
        }
        return sum;
    }

    static bool IsPalindrome(int Number)
    {
        return Number == ReversNum(Number);
    }

    static void PrintInvertedPattern(int Number)
    {
        if (Number < 10)
        {
            for (; Number > 0; Number--)
            {
                for (int i = Number; i > 0; i--)
                    cout << Number;

                cout << endl;
            }
        }
        else
        {
            for (; Number > 0; Number--)
            {
                for (int i = Number; i > 0; i--)
                    cout << Number << " ";

                cout << endl;
            }
        }

    }

    static void PrintInvertedLetterPattern(int Number)
    {

        for (int Letter = 64 + Number; Letter >= 64; Letter--)
        {

            for (int j = Letter - 64; j >= 1; j--)
                cout << (char)Letter;

            cout << "\n";
        }
    }

    static void PrintLetterPattern(int Number)
    {
        for (int Letter = 65; Number >= 1; Letter++)
        {
            Number--;
            for (int j = 1; j <= Number - (65 + Number - 1 - Letter); j++)
                cout << (char)Letter;

            cout << "\n";
        }
    }

    static void PrintAAAtoZZZ()
    {
        for (int i = 65; i <= 90; i++)
        {
            for (int j = 65; j <= 90; j++)
            {
                for (int h = 65; h <= 90; h++)
                {
                    cout << (char)i << (char)j << (char)h << " ";
                }
                cout << "--------\n";
            }
            cout << "=========\n";
        }
    }

    static string Word(int i, int j, int h)
    {
        string word = "";
        word = word + (char)i;
        word = word + (char)j;
        word = word + (char)h;
        return word;
    }

    static bool CheckPass(string Word, string Pass)
    {
        return Word == Pass;
    }

    static void GessPassword(string Pass)
    {
        int counter = 0;
        for (int i = 65; i <= 90; i++)
        {
            for (int j = 65; j <= 90; j++)
            {
                for (int h = 65; h <= 90; h++)
                {
                    counter++;

                    cout << "Trail [" << counter << "] : " << Word(i, j, h) << "\n";

                    if (CheckPass(Word(i, j, h), Pass))
                    {
                        cout << "\nPassword is " << Pass << endl
                            << "found After " << counter << " Trial(s)\n";
                        return;
                    }
                }
                cout << "--------\n";
            }
            cout << "=========\n";
        }
    }

    static void EncryptText(string& Text, short EncryptKey)
    {
        for (int i = 0; i < Text.length(); i++)
        {
            Text[i] += EncryptKey;
        }
    }

    static void DecryptText(string& Text, short EncryptKey)
    {
        for (int i = 0; i < Text.length(); i++)
        {
            Text[i] -= EncryptKey;
        }
    }

    static void Srand()
    {
        srand((unsigned)time(NULL));
    }

    enum enCharType { SmallLetter = 1, CapitalLetter = 2, SpecilCharacter = 3, Digit = 4 };

    static int RandomNumber(int From, int To)
    {
        return rand() % (To - From + 1) + From;
    }

    static char RandomChar(enCharType MyRandom)
    {
        switch (MyRandom)
        {
        case SmallLetter: return (char)RandomNumber(97, 122);
        case CapitalLetter: return (char)RandomNumber(65, 90);
        case SpecilCharacter: return (char)RandomNumber(33, 47);
        case Digit: return (char)RandomNumber(48, 57);
        default: RandomNumber(33, 122);
        }
    }

    static string GenerateWord(enCharType MyRandom, short Length)
    {
        string Word = "";
        for (short i = 0; i < Length; i++)
            Word += RandomChar(MyRandom);

        return Word;
    }

    static string GenearteKey()
    {
        string Key = "";
        for (int i = 0; i < 4; i++)
        {
            Key += GenerateWord(CapitalLetter, 4);

            if (i != 3)
                Key += "-";
        }
        return Key;
    }

    static void FillArrayRandomNum(int MyArray[100], int ArrayLenght)
    {
        for (int i = 0; i < ArrayLenght; i++)
            MyArray[i] = RandomNumber(1, 100);
    }

    static void PrintArray(int MyArray[100], int ArrayLenght)
    {
        cout << endl << "Array Elements : ";

        for (int i = 0; i < ArrayLenght; i++)
            cout << MyArray[i] << "  ";
        cout << endl;
    }

    static int MaxNumInArray(int MyArray[100], int ArrayLenght)
    {
        int MaxNum = 0;
        for (int i = 0; i < ArrayLenght; i++)
        {
            if (MyArray[i] > MaxNum)
                MaxNum = MyArray[i];
        }
        return MaxNum;
    }

    static int MinNumInArray(int MyArray[100], int ArrayLenght)
    {
        int MinNum = MyArray[0];
        for (int i = 0; i < ArrayLenght; i++)
        {
            if (MyArray[i] < MinNum)
                MinNum = MyArray[i];
        }
        return MinNum;
    }

    static int SumNumInArray(int MyArray[100], int ArrayLenght)
    {
        int Sum = 0;
        for (int i = 0; i < ArrayLenght; i++)
            Sum += MyArray[i];

        return Sum;
    }

    static float AverageNumInArray(int MyArray[100], int ArrayLenght)
    {
        return (float)SumNumInArray(MyArray, ArrayLenght) / ArrayLenght;
    }

    static void CopyArray(int MyArray[100], int MyArray2[100], int ArrayLenght)
    {
        for (int i = 0; i < ArrayLenght; i++)
            MyArray2[i] = MyArray[i];
    }

    static void CopyPrimeNumArray(int MyArray[100], int MyArray2[100], int ArrayLenght, int& Arr2Lenght)
    {
        for (int i = 0; i < ArrayLenght; i++)
        {
            if (CheckNumPrime(MyArray[i]) == Prime)
            {
                MyArray2[Arr2Lenght] = MyArray[i];
                Arr2Lenght++;
            }
        }
    }

    static void Sum2ArrayNumbers(int MyArray[100], int MyArray2[100], int ArraySum[100], int ArrayLenght)
    {
        for (int i = 0; i < ArrayLenght; i++)
            ArraySum[i] = MyArray[i] + MyArray2[i];
    }

    static void ShuffleOrderArray(int MyArray[100], int ArrayLenght)
    {
        for (int i = 0; i < ArrayLenght; i++)
            Swap2Numbers(MyArray[RandomNumber(1, ArrayLenght) - 1], MyArray[RandomNumber(1, ArrayLenght) - 1]);
    }

    static void CopyReverseArray(int MyArray[100], int MyArray2[100], int ArrayLenght)
    {
        for (int i = 0; i < ArrayLenght; i++)
            MyArray2[i] = MyArray[ArrayLenght - i - 1];
    }

    static void FillArrayKeys(string Keys[100], int ArrayLenght)
    {
        for (int i = 0; i < ArrayLenght; i++)
            Keys[i] = GenearteKey();

    }

    static short FindNumPositionInArray(int NumSearch, int MyArray[100], int ArrayLenght)
    {
        for (int i = 0; i < ArrayLenght; i++)
        {
            if (MyArray[i] == NumSearch)
                return i;
        }
        return -1;
    }

    static void SearchForNum(int MyArray[100], int ArrayLenght)
    {
        int NumSearch = ReadNumberInRange("Please enter a Number to Search for : ", 0);

        cout << "\nNumber you are looking for is : " << NumSearch << endl << endl;

        int NumPosition = FindNumPositionInArray(NumSearch, MyArray, ArrayLenght);

        if (NumPosition == -1)
            cout << "The Number Not found -)\n";

        else
        {
            cout << "The Number found at position: " << NumPosition << endl;
            cout << "The Number found at order: " << NumPosition + 1 << endl << endl;
        }
    }

    static bool CheckNumInArray(int NumSearch, int MyArray[100], int ArrayLenght)
    {
        return FindNumPositionInArray(NumSearch, MyArray, ArrayLenght) != -1;
    }

    static void AddArrayElement(int Number, int MyArray[100], int& ArrayLenght)
    {
        MyArray[ArrayLenght] = Number;
        ArrayLenght++;
    }

    static void InputUserNumberInArray(int MyArray[100], int& ArrayLenght)
    {
        bool AddMore = true;
        do
        {
            int Number = ReadNumberInRange("Please enter number : ",0);
            AddArrayElement(Number, MyArray, ArrayLenght);

            cout << "do you want to add more numbers? (0/1) : ";
            cin >> AddMore;

        } while (AddMore);

    }

    static void CopyArrayElement(int MyArray[100], int MyArray2[100], int ArrayLenght, int& Arr2Lenght)
    {
        while (Arr2Lenght < ArrayLenght)
            AddArrayElement(MyArray[Arr2Lenght], MyArray2, Arr2Lenght);
    }

    static void CopyOddNumArrayElement(int MyArray[100], int MyArray2[100], int ArrayLenght, int& Arr2Lenght)
    {
        for (int i = 0; i < ArrayLenght; i++)
        {
            if (CheckOddOrEven(MyArray[i]) == Odd)
                AddArrayElement(MyArray[i], MyArray2, Arr2Lenght);
        }

    }

    static void CopyPrimeNumArrayElement(int MyArray[100], int MyArray2[100], int ArrayLenght, int& Arr2Lenght)
    {
        for (int i = 0; i < ArrayLenght; i++)
        {
            if (CheckNumPrime(MyArray[i]) == Prime)
                AddArrayElement(MyArray[i], MyArray2, Arr2Lenght);
        }
    }

    static void CopyDistinctNum(int MyArray[10], int MyArray2[10], int& Arr2Lenght)
    {
        for (int i = 0; i < 10; i++)
        {
            if (!CheckNumInArray(MyArray[i], MyArray2, Arr2Lenght))
                AddArrayElement(MyArray[i], MyArray2, Arr2Lenght);
        }
    }

    static int OddCountInArr(int MyArray[100], int ArrayLenght)
    {
        int OddNumCount = 0;
        for (int i = 0; i < ArrayLenght; i++)
        {
            if (CheckOddOrEven(MyArray[i]) == Odd)
                OddNumCount++;
        }
        return OddNumCount;
    }

    static bool IsPalindromeArray(int MyArray[100], int ArrayLenght)
    {
        for (int i = 0; i < ArrayLenght; i++)
        {
            if (MyArray[i] != MyArray[ArrayLenght - i - 1])
                return 0;
        }
        return 1;
    }

    static int EvenCountInArr(int MyArray[100], int ArrayLenght)
    {
        int EvenNumCount = 0;
        for (int i = 0; i < ArrayLenght; i++)
        {
            if (CheckOddOrEven(MyArray[i]) == Even)
                EvenNumCount++;
        }
        return EvenNumCount;
    }

    static int PositiveCountInArr(int MyArray[100], int ArrayLenght)
    {
        int PositiveNumCount = 0;
        for (int i = 0; i < ArrayLenght; i++)
        {
            if (MyArray[i] >= 0)
                PositiveNumCount++;
        }
        return PositiveNumCount;
    }

    static int NegativeCountInArr(int MyArray[100], int ArrayLenght)
    {
        int NegativeNumCount = 0;
        for (int i = 0; i < ArrayLenght; i++)
        {
            if (MyArray[i] < 0)
                NegativeNumCount++;
        }
        return NegativeNumCount;
    }

    static int MyABS(int Num)
    {
        if (Num > 0)
            return Num;
        else
            return Num * -1;
    }

    static int MyRound(float Number)
    {
        if (Number < 0)
        {
            int Num = Number;
            if (float(Number - Num) < -0.49)
                return Num - 1;
            else
                return Num;
        }

        else
        {
            int Num = Number;
            if (float(Number - Num) > 0.49)
                return Num + 1;
            else
                return Num;
        }
    }

    static float GetFractionNum(float Number)
    {
        return Number - (int)Number;
    }

    static int MyFloor(float Number)
    {
        if (Number >= 0)
            return Number;

        else
        {
            int IntPart = Number;
            float FractionPart = GetFractionNum(Number);
            if (abs(FractionPart) >= 0.5)
                return Number - 1;
            else
                return Number;
        }
    }

    static int MyCeil(float Number)
    {
        int IntPart = Number;
        float FractionPart = GetFractionNum(Number);

        if (FractionPart == 0)
            return Number;

        else
        {
            if (Number < 0)
                return Number;
            else
                return ++Number;
        }

    }

    static float MySqrt(float Number)
    {
        for (float i = 0; i < Number; i += 0.001)
        {
            if (i * i >= Number)
                return int(i * 100) / (float)100;
        }
    }

    static void FillRandomMatrix(int RandomMatrix[3][3], short Rows, short Colms)
    {
        for (int i = 0; i < Rows; i++)
        {
            for (int j = 0; j < Colms; j++)
                RandomMatrix[i][j] = RandomNumber(1, 100);
        }
    }

    static void PrintMatrix(int RandomMatrix[3][3], short Rows, short Colms)
    {
        for (int i = 0; i < Rows; i++)
        {
            for (int j = 0; j < Colms; j++)
                cout << setw(3) << RandomMatrix[i][j] << "\t";

            cout << endl;
        }
    }

    static short RowSum(int RandomMatrix[3][3], short RowNum, short Colms)
    {
        short sum = 0;
        sum = 0;
        for (int i = 0; i < Colms; i++)
        {
            sum += RandomMatrix[RowNum][i];
        }
        return sum;
    }

    static void SumMatrixRowsInArr(int RandomMatrix[3][3], int ArrSumMatrixRows[3], short Rows, short Colms)
    {
        for (int i = 0; i < Colms; i++)
        {
            ArrSumMatrixRows[i] = RowSum(RandomMatrix, i, Colms);
        }
    }

    static short ColmsSum(int RandomMatrix[3][3], short Rows, short ColmNum)
    {
        short sum = 0;
        sum = 0;
        for (int i = 0; i < Rows; i++)
        {
            sum += RandomMatrix[i][ColmNum];
        }
        return sum;
    }

    static void SumMatrixToArr(int Matrix[3][3], int MatrixSum[3], short Rows, short Colms)
    {
        for (int i = 0; i < Colms; i++)
            MatrixSum[i] = ColmsSum(Matrix, 3, i);
    }

    static void FillOrderMatrix(int Matrix[3][3], short Rows, short Colms)
    {
        short Counter = 0;
        for (short i = 0; i < Rows; i++)
        {
            for (short j = 0; j < Colms; j++)
            {
                Counter++;
                Matrix[i][j] = Counter;
            }
        }
    }

    static void FillTransporsedMatrix(int Matrix[3][3], int TransMatrix[3][3], short Rows, short Colms)
    {
        for (short i = 0; i < Colms; i++)
        {
            for (short j = 0; j < Rows; j++)
            {
                TransMatrix[i][j] = Matrix[j][i];
            }
        }
    }

    static int MultiplyCalc(short Number1, short Number2)
    {
        return Number1 * Number2;
    }

    static void MultiplyMatrixs(short Matrix1[3][3], short Matrix2[3][3], short ResultMatrix[3][3], short Rows, short Colms)
    {
        for (int i = 0; i < Rows; i++)
        {
            for (int j = 0; j < Colms; j++)
                ResultMatrix[i][j] = MultiplyCalc(Matrix1[i][j], Matrix2[i][j]);
        }
    }

    static void PrintMidRowsMatrix(short Matrix[3][3], short MidRows, short Colms)
    {
        for (int i = 0; i < Colms; i++)
            printf(" %0*d  ", 2, Matrix[MidRows][i]);
        cout << endl;
    }

    static void PrintMidColmsMatrix(short Matrix[3][3], short Rows, short MidColms)
    {
        for (int i = 0; i < Rows; i++)
            printf(" %0*d  ", 2, Matrix[i][MidColms]);
        cout << endl;
    }

    static int SumMatrix(short Matrix[3][3], short Rows, short Colms)
    {
        int Sum = 0;
        for (int i = 0; i < Rows; i++)
        {
            for (int j = 0; j < Colms; j++)
                Sum += Matrix[i][j];
        }
        return Sum;
    }

    static bool MatrixEquality(short Matrix1[3][3], short Matrix2[3][3], short Rows, short Colms)
    {
        for (int i = 0; i < Rows; i++)
        {
            for (int j = 0; j < Colms; j++)
            {
                if (Matrix1[i][j] != Matrix2[i][j])
                    return false;
            }
        }
        return true;
    }

    static bool CheckIdentityMatrix(short Matrix[3][3], short Rows, short Colms)
    {
        for (int i = 0; i < Rows; i++)
        {
            for (int j = 0; j < Colms; j++)
            {
                if (i == j && Matrix[i][j] != 1)
                    return false;

                else if (i != j && Matrix[i][j] != 0)
                    return false;
            }
        }
        return true;
    }

    static bool IsScalarMatrix(short Matrix[3][3], short Rows, short Colms)
    {
        short CheckNum;
        for (int i = 0; i < Rows; i++)
        {
            for (int j = 0; j < Colms; j++)
            {
                if (i == 0 && j == 0)
                    CheckNum = Matrix[i][j];
                else if (i == j && CheckNum != Matrix[i][j])
                    return false;
                else if (i != j && Matrix[i][j] != 0)
                    return false;
            }
        }
        return true;
    }

    static void SearchNumMatrix(short Matrix[3][3], short Rows, short Colms)
    {
        short SearchNumber = ReadNumber("\nEnter the number to count in Matrix: ");

        short Count = 0;

        for (int i = 0; i < Rows; i++)
        {
            for (int j = 0; j < Colms; j++)
            {
                if (SearchNumber == Matrix[i][j])
                    Count++;
            }
        }

        cout << "\nNumber " << SearchNumber << " Count in matrix is : " << Count << endl;
    }

    static short CountNumberInMatrix(short Matrix[3][3], short Number, short Rows, short Colms)
    {
        short NumberCount = 0;
        for (int i = 0; i < Rows; i++)
        {
            for (int j = 0; j < Colms; j++)
            {
                if (Number == Matrix[i][j])
                    NumberCount++;
            }
        }
        return NumberCount;
    }

    static bool IsSparseMatrix(short Matrix[3][3], short Rows, short Colms)
    {
        short MaxSize = Rows * Colms;

        return (ceil(MaxSize / 2) < CountNumberInMatrix(Matrix, 0, 3, 3));
    }

    static bool IsNumberInMatrix(short Matrix[3][3], short Number, short Rows, short Colms)
    {
        for (int i = 0; i < Rows; i++)
        {
            for (int j = 0; j < Colms; j++)
            {
                if (Number == Matrix[i][j])
                    return true;
            }
        }
        return false;
    }

    static void PrintIntersectNum(short Matrix1[3][3], short Matrix2[3][3], short Rows, short Colms)
    {
        for (short i = 0; i < Rows; i++)
        {
            for (short j = 0; j < Colms; j++)
            {
                if (IsNumberInMatrix(Matrix2, Matrix1[i][j], 3, 3))
                    cout << Matrix1[i][j] << "\t";
            }
        }
        cout << endl;
    }

    static float MaxNumberInMatrix(short Matrix[3][3], short Rows, short Colms)
    {
        float MaxNumber = Matrix[0][0];
        for (int i = 0; i < Rows; i++)
        {
            for (int j = 0; j < Colms; j++)
            {
                if (Matrix[i][j] > MaxNumber)
                    MaxNumber = Matrix[i][j];
            }
        }
        return MaxNumber;
    }

    static float MinNumberInMatrix(short Matrix[3][3], short Rows, short Colms)
    {
        float MinNumber = Matrix[0][0];
        for (int i = 0; i < Rows; i++)
        {
            for (int j = 0; j < Colms; j++)
            {
                if (Matrix[i][j] < MinNumber)
                    MinNumber = Matrix[i][j];
            }
        }
        return MinNumber;
    }

    static bool IsPalindrome(short Matrix[3][3], short Rows, short Colms)
    {
        for (int i = 0; i < Rows; i++)
        {
            for (short j = 0; j < Colms / 2; j++)
            {
                if (Matrix[i][j] != Matrix[i][Colms - 1 - j])
                    return false;
            }
        }
        return true;
    }

    static void PrintFibanacci(int Fibanacci)
    {
        int Num1 = 1, Num2 = 1, Temp = 0, Counter = 2;

        cout << Num1 << "  " << Num2 << "  ";

        for (int i = 2; i < Fibanacci; i++)
        {
            cout << Num1 + Num2 << "  ";
            Temp = Num2;
            Num2 = Num1 + Num2;
            Num1 = Temp;
        }
    }

    static void PrintFibonacciUsingRecursion(short Number, short Prev1, short Prev2)
    {
        int FebNumber = 0;
        if (Number > 0)
        {
            FebNumber = Prev1 + Prev2;
            Prev1 = Prev2;
            Prev2 = FebNumber;
            cout << FebNumber << "\t";
            PrintFibonacciUsingRecursion(Number - 1, Prev1, Prev2);
        }
    }

    static void Convert(string& TextNumber, int& Number, short j = 0)
    {
        vector <string> vTextNumber = { "", "One", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

        vector <string> vTextNumber2 = { "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen",
                                        "eighteen", "nineteen", };

        vector <string> vTextNumber3 = { "twenty", "thirty", "forty", "fifty", "sixty", "seventy",
                                        "eighty", "ninety" };

        vector <string> vTextNumber4 = { "hundred", "thousand", "million", "billion" };


        if (Number - ((Number / 100) * 100) <= 9)
        {
            if (!(Number - ((Number / 10) * 10) == 0))
                TextNumber = vTextNumber[Number - ((Number / 100) * 100)] + TextNumber;
            Number /= 100;
        }
        else if (Number - ((Number / 100) * 100) <= 19)
        {
            TextNumber = vTextNumber2[Number - ((Number / 100) * 100) - 10] + TextNumber;
            Number /= 100;
        }
        else if (Number - ((Number / 100) * 100) <= 99)
        {
            if (!(Number - ((Number / 10) * 10) == 0))
                TextNumber = vTextNumber[Number - ((Number / 10) * 10)] + TextNumber;
            Number /= 10;

            TextNumber = vTextNumber3[Number - ((Number / 10) * 10) - 2] + " " + TextNumber;
            Number /= 10;
        }

        if (Number - ((Number / 10) * 10) <= 9)
        {
            if (!(Number - ((Number / 10) * 10) == 0))
                TextNumber = vTextNumber[Number - ((Number / 10) * 10)] + " " + vTextNumber4[0] + " " + TextNumber;
            Number /= 10;
        }


        if (Number > 0)
        {
            j++;
            TextNumber = " " + vTextNumber4[j] + " " + TextNumber;
            Convert(TextNumber, Number, j);
        }

    }

    static string ConvertNumberToText(int Number)
    {
        string TextNumber = "";

        Convert(TextNumber, Number);

        return TextNumber;
    }
};

