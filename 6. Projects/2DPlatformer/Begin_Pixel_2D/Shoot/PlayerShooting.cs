using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerShooting: MonoBehaviour
{
    [SerializeField]private float shootCooldown;
    [SerializeField] private Transform firePoint; //
    [SerializeField] private GameObject[] fireballs; //������ 10���� fireball(Ǯ�̶��ð� ���������ſ��� �������� ���� �迭)


    private Animator anim;
    private PlayerMovement playerMovement;
    private float cooldownTimer = Mathf.Infinity;

    private void Awake()
    {
        anim = GetComponent<Animator>();
        playerMovement = GetComponent<PlayerMovement>();
    }

    private void Update()
    {
        if (Input.GetMouseButton(0) && cooldownTimer > shootCooldown && playerMovement.canShoot())
            Shoot();

        cooldownTimer += Time.deltaTime;
    }

    private void Shoot()
    {

        anim.SetTrigger("shoot");
        cooldownTimer = 0; //�����Ҷ� �ٷ� ������ ���ϰԲ� �ϴ� ��ġ
        //pool (Object Pool)
        // =>������ Ȯ����Ű�� ���� �����.
        // ������Ʈ�� �����ϰ� �ı��ϴ� �۾��� �ϳ� ���ſ� �۾����� �з���.
        // ������Ʈ ������ �޸𸮸� ���� �Ҵ��ϰ� ���ҽ��� �ε��ϴ� ���� �ʱ�ȭ ��������,
        // �ı� ���� �߻��ϴ� ������ �÷������� ���� ������ ����� �߻��� �� �ִ�.
        // ���ӿ� �ʿ��� ������Ʈ�� �̸� �����ؼ� �ʿ��Ҷ����� ��������, ������ �ٽ� Ǯ�� ������ 
        // �ı��� �ƴ� ������ ���۵ɋ� �ʿ��Ѹ�ŭ�� ������Ʈ�� �����ϰ� ���ڶ�� �߰� �����ϰ� ������ �ı��ϴ� ���.

        fireballs[0].transform.position = firePoint.position;
        fireballs[0].GetComponent<Projectile>().SetDirection(Mathf.Sign(transform.localScale.x));
    }
}
