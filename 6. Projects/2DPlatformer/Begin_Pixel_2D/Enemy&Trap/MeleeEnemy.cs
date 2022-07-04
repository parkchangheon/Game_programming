using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MeleeEnemy : MonoBehaviour
{
    [SerializeField] private float attackCooldown;
    [SerializeField] private float range;
    [SerializeField] private int damage;
    [SerializeField] private BoxCollider2D boxCollider;
    [SerializeField] private LayerMask playerLayer;
    private float cooldownTimer = Mathf.Infinity;

    private void Update()
    {
        cooldownTimer += Time.deltaTime;

        //Attack when only player is in sight
        if(PlayerInsight())
        {
            if (cooldownTimer > attackCooldown)
            {
                // Attack

            }
        }

    }

    private bool PlayerInsight()
    {  
        // transform.right * range �� ������ �ڽ��� range��ŭ �����̰� �ϱ� �����̴�.
        // localScale.x�� �Ѱ���, ������ �����϶�, �ø��� ���ֱ� ����.
        RaycastHit2D hit = Physics2D.BoxCast(boxCollider.bounds.center + -transform.right * range * transform.localScale.x, 
            boxCollider.bounds.size, 0, Vector2.left, 0, playerLayer);   //origin, size, angle, direction
        return hit.collider != null;
    }

    private void OnDrawGizmos() // 
    {
        Gizmos.color = Color.red;
        Gizmos.DrawWireCube(boxCollider.bounds.center + -transform.right * range * transform.localScale.x, boxCollider.bounds.size);
    }
}
