using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Health : MonoBehaviour
{
    [SerializeField] private float startingHealth;
    private float currentHealth;

    private void Awake()
    {
        currentHealth = startingHealth;
    }

    public void TakeDamage(float _damage)
    {
        currentHealth = Mathf.Clamp(currentHealth - _damage, 0, startingHealth);   // value, min, max�� �����Ǿ� ������, value�� min ���� ������ min�� ���� max���� ũ�� max ����
        
        if(currentHealth > 0)
        {
            //player hurt
        }
        else
        {
            // player dead
        }


    }
}
