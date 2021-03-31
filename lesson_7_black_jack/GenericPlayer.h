#pragma once
#include <iostream>
#include <string>
#include "Hand.h"

class GenericPlayer : public Hand
{
    friend std::ostream& operator<<(std::ostream& os, const GenericPlayer& aGenericPlayer);

public:
    GenericPlayer(const std::string& name = "");

    virtual ~GenericPlayer();

    // ����������, ����� �� ����� ���������� ����� �����
    // ��� ������ GenericPlayer ������� �� ����� ����� ����������,
    // �.�. ��� ������ � ������ ��� ����� ������ �������
    virtual bool isHitting() const = 0;

    // ���������� ��������, ���� ����� ����� ������� -
    // ����� ����� ������� 21
    // ������ ������� �� �����������, �.�. ����� ���������� ����������
    // ��� ������ � ������
    bool isBusted() const;

    // ���������, ��� ����� ����� �������
    // ������� ��������� ��� ��� ������, ��� � ��� ������
    void bust() const;

protected:
    std:: string m_name;
};

std::ostream& operator<<(std::ostream& os, const GenericPlayer& aGenericPlayer);