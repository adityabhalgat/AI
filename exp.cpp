#include <iostream>
#include <unistd.h>
using namespace std;

int main(){

    cout << "========================================" << endl;
    cout << "EMPLOYEE PERFORMANCE EVALUATION SYSTEM" << endl;
    cout << "========================================" << endl;

    string employeeName;
    char ans;
    int totalScore;

    cout << "Enter the name of employee: ";
    getline(cin, employeeName);

    cout << "Answer these questions: " << endl;

    string q[15] = {
        "\n1. How punctual is the employee?\n(A: Always  B: Mostly  C: Sometimes  D: Rarely)",
        "2. Work quality?\n(A: Excellent  B: Good  C: Average  D: Poor)",
        "3. Team collaboration?\n(A: Very Good  B: Good  C: Average  D: Weak)",
        "4. Communication skills?\n(A: Excellent  B: Good  C: Average  D: Poor)",
        "5. Task completion rate?\n(A: Always  B: Mostly  C: Sometimes  D: Rarely)",
        "6. Problem solving ability?\n(A: Strong  B: Good  C: Average  D: Weak)",
        "7. Leadership skills?\n(A: Strong  B: Moderate  C: Low  D: None)",
        "8. Adaptability?\n(A: High  B: Good  C: Average  D: Low)",
        "9. Initiative taken?\n(A: Always  B: Often  C: Sometimes  D: Never)",
        "10. Attendance?\n(A: Excellent  B: Good  C: Average  D: Poor)",
        "11. Creativity?\n(A: High  B: Good  C: Average  D: Low)",
        "12. Discipline?\n(A: Very Good  B: Good  C: Average  D: Weak)",
        "13. Responsibility handling?\n(A: Excellent  B: Good  C: Average  D: Poor)",
        "14. Learning ability?\n(A: Fast  B: Good  C: Average  D: Slow)",
        "15. Overall contribution?\n(A: High  B: Good  C: Average  D: Low)"
    };

    for(int i = 0; i < 15; i++){
        while(true){
            cout << q[i] << endl;
            cout << "Answer: ";
            cin >> ans;

            if(ans == 'A' || ans == 'a'){
                totalScore += 4;
                break;
            } else if(ans == 'B' || ans == 'b'){
                totalScore += 3;
                break;
            } else if(ans == 'C' || ans == 'c'){
                totalScore += 2;
                break;
            } else if(ans == 'D' || ans == 'd'){
                totalScore += 1;
                break;
            } else {
                cout << "Invalid option, please choose from A, B, C or D!" << endl;
            }
        }
        cout << endl;
    }

    cout << "Analyzing your results..." << endl;
    sleep(5);

    float percentage = (totalScore/60.0) * 100;

    cout << "========================================" << endl;
    cout << "          EVALUATION RESULT             " << endl;
    cout << "========================================" << endl;

    cout << "Employee Name           :" << employeeName << endl;
    cout << "Total Score             :" << totalScore << "/60" << endl;
    cout << "Percentage              :" << percentage << endl;

    cout << "----------------------------------------" << endl; 

    if(percentage >= 85){
        cout << "Grade                : A+" << endl;
        cout << "Performance Level    : EXCELLENT" << endl;
        cout << "Expert Advice        : Great employee. Should consider promotion or incentives" << endl;
    } else if(percentage >= 70){
        cout << "Grade                : A" << endl;
        cout << "Performance Level    : GOOD" << endl;
        cout << "Expert Advice        : Good employee. Provide advanced skill opportunites" << endl;
    } else if(percentage >= 50){
        cout << "Grade                : B+" << endl;
        cout << "Performance Level    : AVERAGE" << endl;
        cout << "Expert Advice        : Satisfactory employee. Needs improvement." << endl;
    } else {
        cout << "Grade                : B" << endl;
        cout << "Performance Level    : POOR" << endl;
        cout << "Expert Advice        : Poor performer. Needs immediate improvement or put on PIP" << endl;
    }
    return 0;
}