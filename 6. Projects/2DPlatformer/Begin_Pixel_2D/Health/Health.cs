using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Health : MonoBehaviour
{
    [SerializeField] private float startingHealth;
    public float currentHealth { get; private set;  } //get�� �� � ��ũ��Ʈ���� �ش� ���� ���� �� �ִٴ� ���̰�, private set�� ���� ��ũ��Ʈ������ set�� �����ϴٴ� ��.
    private Animator anim;
    private bool dead;


    private void Awake()
    {
        currentHealth = startingHealth;
        anim = GetComponent<Animator>();
    }

    public void TakeDamage(float _damage)
    {
        currentHealth = Mathf.Clamp(currentHealth - _damage, 0, startingHealth);   // value, min, max�� �����Ǿ� ������, value�� min ���� ������ min�� ���� max���� ũ�� max ����
        
        if(currentHealth > 0)
        {
            //player hurt
            anim.SetTrigger("hurt");
        }
        else
        {
            // player dead
            if (!dead)
            {
                anim.SetTrigger("die");
                GetComponent<PlayerMovement>().enabled = false;
                dead = true;
            }
        }


    }

    public void AddHealth(float _value)
    {
        currentHealth = Mathf.Clamp(currentHealth + _value, 0, startingHealth);   // value, min, max�� �����Ǿ� ������, value�� min ���� ������ min�� ���� max���� ũ�� max ����

    }

}
