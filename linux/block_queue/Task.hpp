#pragma once

#include <iostream>
#include <string>

class Task
{
public:
    Task(int x, int y, char oper) : data1_(x), data2_(y), operator_(oper) {}
    void run()
    {
        switch (operator_)
        {
        case '+':
            result_ = data1_ + data2_;
            break;
        case '-':
            result_ = data1_ - data2_;
            break;
        case '*':
            result_ = data1_ * data2_;
            break;
        case '/':
            if (data2_ == 0)
            {
                exit_code_ = 1;
            }
            else
            {
                result_ = data1_ / data2_;
            }
            break;
        case '%':
            if (data2_ == 0)
            {
                exit_code_ = 2;
            }
            else
            {
                result_ = data1_ % data2_;
            }
            break;
        default:
            break;
        }
    }
    std::string printResult()
    {
        std::string r = std::to_string(data1_);
        r += operator_;
        r += std::to_string(data2_);
        r += "=";
        r += std::to_string(result_);
        r += "[";
        r += std::to_string(exit_code_);
        r += "]";
        return r;
    }
    ~Task() {}

private:
    int data1_;
    int data2_;
    char operator_;

    int result_;
    int exit_code_;
};