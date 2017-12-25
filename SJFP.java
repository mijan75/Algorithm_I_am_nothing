List<NonPreemtive> models = new ArrayList<>();
        List<NonPreemtive> tempModelList = new ArrayList<>();


        System.out.println("Enter the number of process");
        Scanner scanner = new Scanner(System.in);
        int numberOfprocess = scanner.nextInt();
        int totalTime = 0;

        for (int i = 1; i <= numberOfprocess; i++) {

            System.out.println("Name of the process: " + i);
            int nameOfProcess = scanner.nextInt();
            System.out.println("Arrival time: "+ i);
            int arrivalTime = scanner.nextInt();
            System.out.println("Burst time of the process: " + i);
            int brustTime = scanner.nextInt();


            NonPreemtive nonPreemtive = new NonPreemtive();
            nonPreemtive.setProcessName(nameOfProcess);
            nonPreemtive.setArrivalTime(arrivalTime);
            nonPreemtive.setBrustTime(brustTime);
            nonPreemtive.setUnitTime(brustTime);
            nonPreemtive.setDone(false);
            totalTime += brustTime;
            models.add(nonPreemtive);
            tempModelList.add(nonPreemtive.copy(nonPreemtive));
        }


        for(int i=0; i<totalTime;){
            int minUnit = totalTime, index = 0;

            for(int j=0; j<numberOfprocess; j++){
                if(models.get(j).getUnitTime() > 0 && models.get(j).getArrivalTime() <=i && models.get(j).getUnitTime() < minUnit){
                    minUnit = models.get(j).getUnitTime();
                    index = j;
                }

            }
            i++;
            models.get(index).setUnitTime(models.get(index).getUnitTime() - 1);
            if (models.get(index).getUnitTime() == 0)
                models.get(index).setFinishTime(i);
        }

        for(int i=0; i<numberOfprocess; i++){
            int waitingTime = models.get(i).getFinishTime() - models.get(i).getBrustTime() - models.get(i).getArrivalTime();
            models.get(i).setWaitingTime(waitingTime);
        }

        double averageTime = 0;
        double turnAroundTime = 0;

        for(int i=0; i<numberOfprocess; i++){
            averageTime+= models.get(i).getWaitingTime();
            turnAroundTime += models.get(i).getWaitingTime() + models.get(i).getBrustTime();
        }

        System.out.println("Average waiting time: "+ averageTime/models.size());
        System.out.println("Average turn around time: "+ turnAroundTime/models.size());


    }
