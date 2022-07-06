using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MeleeEnemy : MonoBehaviour
{
    [Header("Attack Parameter")]
    [SerializeField] private float attackCooldown;
    [SerializeField] private float range;
    [SerializeField] private int damage;

    [Header("Collider Parameter")]
    [SerializeField] private float colliderDistance;
    [SerializeField] private BoxCollider2D boxCollider;
    
    [Header("Player Layer")]
    [SerializeField] private LayerMask playerLayer;
    private float cooldownTimer = Mathf.Infinity;
    private Animator anim;

    private Health PlayerHealth;

    private EnemyPatrol enemyPatrol;


    private void Awake()
    {
        anim = GetComponent<Animator>();
        enemyPatrol = GetComponentInParent<EnemyPatrol>();
    }


    private void Update()
    {
        cooldownTimer += Time.deltaTime;

        //Attack when only player is in sight
        if(PlayerInsight())
        {
            if (cooldownTimer > attackCooldown)
            {
                // Attack
                cooldownTimer = 0; //���� ��� ������ ������, ��ٿ� Ÿ�̸Ӹ� �ʱ�ȭ���ش�.
                anim.SetTrigger("MeleeAttack");
            }
        }

        if (enemyPatrol != null)
            enemyPatrol.enabled = !PlayerInsight();

    }

    private bool PlayerInsight()
    {  
        // transform.right * range �� ������ �ڽ��� range��ŭ �����̰� �ϱ� �����̴�.
        // localScale.x�� �Ѱ���, ������ �����϶�, �ø��� ���ֱ� ����.
        RaycastHit2D hit = Physics2D.BoxCast(boxCollider.bounds.center + -transform.right * range * transform.localScale.x * colliderDistance, 
            new Vector3(boxCollider.bounds.size.x * range, boxCollider.bounds.size.y, boxCollider.bounds.size.z), 
            0, Vector2.left, 0, playerLayer);   //origin, size, angle, direction
        if (hit.collider != null)
        {
            PlayerHealth = hit.transform.GetComponent<Health>();
        }

        return hit.collider != null;



    }

    private void OnDrawGizmos() // 
    {
        Gizmos.color = Color.red;
        Gizmos.DrawWireCube(boxCollider.bounds.center + -transform.right * range * transform.localScale.x * colliderDistance,
             new Vector3(boxCollider.bounds.size.x * range, boxCollider.bounds.size.y, boxCollider.bounds.size.z));
    }


    private void DamagePlayer()
    {
        if (PlayerInsight())
        {
            //Damage player health
            PlayerHealth.TakeDamage(damage);
        }
    }
}
