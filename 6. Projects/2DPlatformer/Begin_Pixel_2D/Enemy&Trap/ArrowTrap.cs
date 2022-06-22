using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ArrowTrap : MonoBehaviour
{
    [SerializeField] private float attackCooldown;
    [SerializeField] private Transform firePoint;
    [SerializeField] private GameObject[] arrows;
    private float CooldownTimer;
    private void Attack()
    {
        CooldownTimer = 0;
        arrows[FindArrowl()].transform.position = firePoint.position;   // fireball position setting
        arrows[FindArrowl()].GetComponent<EnemyProjectile>().ActivateProjectile();  //fireball projectile direction setting
    }

    private int FindArrowl()
    {
        for(int i=0;i< arrows.Length;i++)
        {
            if (!arrows[i].activeInHierarchy)      //fireballs[i].setActive�� ���� ��Ȳ�� ���ϸ�, �θ� �ִٸ�, �θ� ������. (�θ� active false �̸� �ڽĵ� false)
            { //���� ��� ���� ������Ʈ�� selfActive = true�ε�, activeinHierarchy ���� false �̸�, ������Ʈ�� �θ� ������Ʈ�� Ȱ��ȭ ���� �ʾҴٶ�� ��. 
                return i;
            }
        }
        return 0;  //fireball�� ������ 0�� �����Ѵ�.
    }

    private void Update()
    {
        CooldownTimer += Time.deltaTime;

        if (attackCooldown <= CooldownTimer)
            Attack();
        
    }

}
