#include<iostream>
using namespace std;

// �����ڿ��� ȣ��Ǵ� �Լ��� �� �ű⼭ ȣ��Ǵ��� �Ƴ�?

// ������ ���� ������ ��� �ҷ��� ���ΰ�?



//1) 

/*
Unreal Engine���� Createdefaultsubobject �Լ��� UObject�� ���� ������Ʈ�� �����ϴ� �Լ�.
�� �Լ��� �Ϲ������� AActor�� ���� UObject�� �Ļ� Ŭ�������� ���ȴ�.
Createdefaultsubobject �Լ��� �ٸ� UObject�� ��� ������ ������ UObject�� ������ �� ���ȴ�.

Createdefaultsubobject �Լ��� �����ڿ��� ȣ��Ǵ� ������ �� �Լ��� ����Ͽ� ��� ������ �ʱ�ȭ�� ��, �ش� ��� ������ �����ڿ��� �����Ǿ�� �ϱ� ����. 
�Ϲ������� UObject�� ��� ������ �����ڿ��� �����Ǹ�, ���� Createdefaultsubobject �Լ��� ����Ͽ� ������ UObject�� �� ��� ������ �Ҵ��մϴ�.

�׷��ٸ�, Createdefaultsubobject �Լ��� ������ �̿��� �ٸ� �Լ����� ����ϴ� ���� �����Ѱ���? �Ϲ������δ� �����մϴ�. ������ UObject�� �ʱ�ȭ�Ǳ� ������ ȣ��Ǹ� ����ġ ���� ����� �� �� �����Ƿ� �����ؾ� �մϴ�. Createdefaultsubobject �Լ��� ����Ͽ� ������ UObject�� �װ��� �����ϴ� UObject�� �Բ� �ı��ǹǷ�, Createdefaultsubobject �Լ��� ȣ���� �Լ��� ������ UObject�� ���� �������� ������ �־�� �մϴ�.

���������, Createdefaultsubobject �Լ��� UObject�� �ʱ�ȭ�ϱ� ���� �����ڿ��� ȣ��Ǹ�, UObject�� ��� ������ �ʱ�ȭ�ϴ� �� �߿��� ������ �մϴ�. Createdefaultsubobject �Լ��� ������ �̿ܿ��� ����� ���� ���ǰ� �ʿ��ϸ�, ������ UObject�� �����ǿ� ���� å���� �ֽ��ϴ�.
*/

void AMyCharacter::GetMonstersInRange()
{
    const FVector Start = GetActorLocation();
    const FVector ForwardVector = GetActorForwardVector();

    const float SphereRadius = 500.f; // Sphere Trace �ݰ� ����
    const float HalfAngle = 15.f;
    const float StartAngle = -HalfAngle;
    const float EndAngle = HalfAngle;
    const int32 NumSweeps = 10;
    const float Increment = (EndAngle - StartAngle) / NumSweeps;

    TArray<FHitResult> HitResults;

    for (int32 i = 0; i < NumSweeps; ++i)
    {
        const float Angle = StartAngle + (i * Increment);
        const FVector SweepDirection = ForwardVector.RotateAngleAxis(Angle, FVector(0.f, 0.f, 1.f));
        const FVector End = Start + (SweepDirection * SphereRadius);

        FCollisionQueryParams TraceParams;
        TraceParams.AddIgnoredActor(this);

        TArray<FHitResult> TempHitResults;

        if (GetWorld()->SweepMultiByChannel(TempHitResults, Start, End, FQuat::Identity, ECC_Visibility, FCollisionShape::MakeSphere(SphereRadius), TraceParams))
        {
            HitResults.Append(TempHitResults);
        }
    }

    for (const FHitResult& HitResult : HitResults)
    {
        AMyMonster* Monster = Cast<AMyMonster>(HitResult.GetActor());
        if (Monster)
        {
            // ���� ������ ����� �ڵ� �ۼ�
        }
    }
}

//2)
/*
Line Trace ���
Line Trace ����� ĳ������ �þ� ���⿡ ������ �׾� �ش� ��ġ�� �ִ� ������Ʈ�� �˻��ϴ� ����Դϴ�.�� ����� �ش� ��ġ�� �ִ� ��� ������Ʈ�� ã�� �� �ֱ� ������, 
���� ���� ���Ͱ� ���� �� ���� ����� ���͸� �����Ϸ��� �Ÿ� ����� �߰��� ���־�� �մϴ�.

Sphere Trace ���
Sphere Trace ����� Line Trace�� ���������, ���� �ݰ� ���� �ִ� ��� ������Ʈ�� �˻��ϴ� ����Դϴ�.
�� ����� Line Trace���� �� ���� �˻� ������ �����Ƿ�, ���� ���Ͱ� ���� �� ���� ����� ���͸� �����ϱ� �� ���� �� �ֽ��ϴ�.

Overlap Sphere ���
Overlap Sphere ����� ���� �ݰ� ���� �ִ� ��� ������Ʈ�� �浹 �˻縦 �ϴ� ����Դϴ�.Overlap Sphere�� �ݸ��� �˻縦 �ϴ� ���̱� ������, ĳ���Ϳ� ������ �ݸ��� ������ �ʿ��մϴ�.

���� ����� �߿��� �����Ͽ� ����� �� ������, ������ ������ �ҷ����� ����� �������� �ʿ信 ���� �پ��մϴ�.�� ����� �˻� �ӵ�, ��Ȯ��, ������ ���⵵ ���� ����Ͽ� �����ϸ� �˴ϴ�.
*/


