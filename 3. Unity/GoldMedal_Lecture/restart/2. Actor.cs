using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Actor : MonoBehaviour
{
    
    int id;
    public string name;
    string title;
    string weapon;
    float strength;
    public int level = 10;

    public string Talk()
    {
        return "��ȭ�� �ɴ�";
    }


    public string HasWeapon()
    {
        return weapon;
    }

    public void LevelUp()
    {
        level += 1;
        Debug.Log("������ �ö����ϴ�!!");
    }
}
