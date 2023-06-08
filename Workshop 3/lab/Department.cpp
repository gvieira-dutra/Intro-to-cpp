#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Department.h"
#include "string.h"

using namespace std;

namespace sdds {

    Department::Department() {
        projNum = 0;
        dptBudget = 15345.99;
        dptName = NULL;
    }

    //fully provided for students to display details of a project
    void display(const Project& project) {
        cout << "Project " << project.m_topic
            << " will cost a total of " << project.m_cost << " C$." << endl;
    }

    //fully provided for students to display details of a department
    void display(const Department& department) {
            Project* temp = department.fetchProjects();
            int projects = department.fetchNumProjects();
            cout << "Department " << department.fetchName() << " details:" << endl;
            cout << "Budget: " << department.fetchBudget()
                << " and the number of projects in progress is: " << projects << endl;
            cout << "Below are the details of the projects we are currently working on: " << endl;
            for (int i = 0; i < projects; i++) {
                display(temp[i]);
            }
    }

    void Department::updateName(const char* newname) {
        
        if (dptName != nullptr)
        {
            delete[] dptName;
            
        }

        if (newname != nullptr && newname[0] != '\0')
        {
            dptName = new char[strlen(newname) + 1];
            strcpy(dptName, newname);
        }
    }

    void Department::updateBudget(double change)
    {
        dptBudget += change;
    }

    bool Department::addProject(Project& newproject)
    {
        bool check = true;
        double totalCost = 0;

        projNum++;

        if (projNum > 1)
        {
            for (int i = 0; i < projNum - 1; i++)
            {
                totalCost += dptProj[i].m_cost;
            }
            totalCost += newproject.m_cost;
        }
        

        if ((totalCost) < dptBudget)
        {
            if (projNum == 1)
            {
                dptProj = nullptr;
                dptProj = new Project[1];
                dptProj[0].m_cost = newproject.m_cost;
                strcpy(dptProj[0].m_topic, newproject.m_topic);
               
            }
            else
            {
                Project* tempProj = nullptr;
                tempProj = new Project[projNum];

                for (int i = 0; i < projNum - 1; i++)
                {
                    tempProj[i].m_cost = dptProj[i].m_cost;
                    strcpy(tempProj[i].m_topic, dptProj[i].m_topic);
                }

                

                tempProj[projNum - 1].m_cost = newproject.m_cost;
                strcpy(tempProj[projNum - 1].m_topic, newproject.m_topic);

                delete[] dptProj;

                dptProj = new Project[projNum];

                for (int i = 0; i < projNum; i++)
                {
                    dptProj[i].m_cost = tempProj[i].m_cost;
                    strcpy(dptProj[i].m_topic, tempProj[i].m_topic);
                }
                delete[] tempProj;
            }
        }
        else
        {
            check = false;
            projNum--;
        }

        return check;
    }

    void Department::createDepartment(const char* newname,
        Project& newproject,
        double change)
    {
        updateName(newname);
        addProject(newproject);
        updateBudget(change);
    }

    Project* Department::fetchProjects() const
    {
        return dptProj;
    }

    int Department::fetchNumProjects() const
    {
        return projNum;
    }

    double Department::fetchBudget() const
    {
        return dptBudget;
    }

    char* Department::fetchName() const
    {
        return dptName;
    }

    double Department::totalexpenses()
    {
        double totalExpense = 0;
        for (int i = 0; i < projNum; i++)
        {
            totalExpense += dptProj[i].m_cost;
        }
        return totalExpense;
    }

    double Department::remainingBudget()
    {
        double totalExpense = 0;
        double remainBalance;
        for (int i = 0; i < projNum; i++)
        {
            totalExpense += dptProj[i].m_cost;
        }

        remainBalance = dptBudget - totalExpense;

        return remainBalance;
    }

    void Department::clearDepartment()
    {
        delete[] dptProj;
        delete[] dptName;
    }
}